#include "mesh.hpp"

#include "arrayUtils.hpp"

namespace JRenderer {

Mesh::Mesh() {
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &elementBuffer);
    glGenVertexArrays(1, &arrayBuffer);
}

Mesh::Mesh(const float (&data)[], int dSize, const unsigned int (&indices)[], int iSize): Mesh() {
    this->data = JRenderer::toFloatVector(data, dSize);
    this->indices = JRenderer::toUIntVector(indices, iSize);
}

Mesh::Mesh(std::vector<float> data, std::vector<unsigned int> indices): Mesh() {
    this->data = data;
    this->indices = indices;
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &elementBuffer);
    glDeleteVertexArrays(1, &arrayBuffer);
}

float* Mesh::toVertexArray() {
    return &(this->data)[0];
}

unsigned int* Mesh::toElementArray() {
    return &(this->indices)[0];
}

int Mesh::vertexSize() {
    return this->data.size() * sizeof(float);
}

int Mesh::indexSize() {
    return this->indices.size() * sizeof(unsigned int);
}

void Mesh::queueUpdate() {
    this->updateQueued = true;
}

std::vector<float> Mesh::prepare(float vertices[], float texCoords[]) {
    const int VERTICES_PER_TRIANGLE = 3;
    const int INDICES_PER_TEXCOORD = 2;

    std::vector<float> data;

    int len = sizeof(*vertices) / sizeof(vertices[0]);

    for (int v = 0, t = 0; v < len;) {
        for (int j = 0; j < VERTICES_PER_TRIANGLE; ++j, ++v) {
            data.push_back(vertices[v]);
        }

        for (int j = 0; j < INDICES_PER_TEXCOORD; ++j, ++t) {
            data.push_back(texCoords[t]);
        }
    }

    return data;
}

Mesh* Mesh::createFromFile(std::string filePath) {

    std::string string = std::string(filePath);
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile(string, aiProcess_Triangulate | aiProcess_CalcTangentSpace);

#ifndef RELEASE
    if (!scene) {
        //JRenderer::error("Model import error: " + std::string(importer.GetErrorString()));
        std::terminate;
    }
#endif

    aiNode *root = scene->mRootNode;
    root = root->mChildren[0];

    Mesh* mesh = new Mesh();
       
    if (root->mNumMeshes == 0) {
        return mesh;
    }

    aiMesh *importedMesh = scene->mMeshes[root->mMeshes[0]];

    std::vector<float> data;
    std::vector<unsigned int> indices;

    bool hasTextureCoords = importedMesh->mTextureCoords[0];
    bool hasNormals = importedMesh->HasNormals();

    mesh->hasTextureCoords = hasTextureCoords;
    mesh->hasNormals = hasNormals;

    for (int i = 0; i < importedMesh->mNumVertices; ++i) {
        // Vertex location
        data.push_back(importedMesh->mVertices[i].x);
        data.push_back(importedMesh->mVertices[i].y);
        data.push_back(importedMesh->mVertices[i].z);

        // Texture coords
        if (hasTextureCoords) {
            data.push_back(importedMesh->mTextureCoords[0][i].x);
            data.push_back(importedMesh->mTextureCoords[0][i].y);
        }

        // Mesh normals
        if (hasNormals) {
            data.push_back(importedMesh->mNormals[i].x);
            data.push_back(importedMesh->mNormals[i].y);
            data.push_back(importedMesh->mNormals[i].z);
        }
    }

    for (int i = 0; i < importedMesh->mNumFaces; ++i) {
        aiFace face = importedMesh->mFaces[i];

        for (int j = 0; j < face.mNumIndices; ++j) {
            indices.push_back(face.mIndices[j]);
        }
    }

    mesh->data = std::move(data);
    mesh->indices = std::move(indices);

/* TODO: Support images
# include <iostream>

    aiMaterial *material = scene->mMaterials[0];
    aiString imagePath;

    if (material->GetTextureCount(aiTextureType_DIFFUSE) != 0) {
        material->GetTexture(aiTextureType_DIFFUSE, 0, &imagePath);
        std::cout<< imagePath.C_Str() << std::endl;
    }
*/
    return mesh;
}
}