#ifndef MESH_H
#define MESH_H

#include <iterator>
#include <vector>
#include <glm/glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "arrayUtils.hpp"
#include "material.hpp"

namespace JRenderer {

class Mesh {
    public:

    std::vector<float> data;
    std::vector<unsigned int> indices;
    glm::mat4 matrix = glm::mat4(1.0f);

    bool hasTextureCoords = false;
    bool hasNormals = false;

    bool updateQueued = true;

    JRenderer::Material material;

    unsigned int vertexBuffer;
    unsigned int arrayBuffer;
    unsigned int elementBuffer;

    unsigned int lastTexture = -1;

    Mesh();
    Mesh(const float (&data)[], int dSize, const unsigned int (&indices)[], int iSize);
    Mesh(std::vector<float> data, std::vector<unsigned int> indices);

    ~Mesh();

    float* toVertexArray();
    unsigned int* toElementArray();

    int vertexSize();
    int indexSize();

    void queueUpdate();

    static Mesh* createFromFile(std::string filePath);

    static std::vector<float> prepare(float vertices[], float texCoords[]);
};

}

#endif