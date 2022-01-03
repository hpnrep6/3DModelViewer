#include "renderer.hpp"

namespace {
bool initialised = false;

unsigned int lastShader = -1;

int lastWidth = -1, 
    lastHeight = -1;

}

namespace JRenderer {

void Renderer::init() {
    if (initialised) {
        return;
    }

    int w = 800;
    int h = 800;

    initialised = true;
}

Renderer::Renderer() {
    
}

void Renderer::clear() {
    glClearColor(0.f, 0.2f, 0.f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_BACK);
    // glFrontFace(GL_CCW);
}

void Renderer::render(Camera &camera, JRenderer::Mesh &mesh, unsigned int texture) {
    glm::mat4 view = camera.view;
    glm::mat4 projection = camera.projection;
    glm::mat4 model = mesh.matrix;

    glBindVertexArray(mesh.arrayBuffer);

    unsigned int shader = mesh.material.shader.shader;

    // Update dimensions of viewport if viewport size changed
   if (lastWidth != camera.width || lastHeight != camera.height) {
        glViewport(0, 0, camera.width, camera.height);
        lastWidth = camera.width;
        lastHeight = camera.height;
   }

    // Only change shaders if it's a different one
   if (shader != lastShader) {
        glUseProgram(shader);

        const char* viewName = mesh.material.shader.viewName.c_str();
        const char* projectionName = mesh.material.shader.projectionName.c_str();
        const char* modelName = mesh.material.shader.modelName.c_str();

        this->viewLoc = glGetUniformLocation(shader, viewName);
        this->projectionLoc = glGetUniformLocation(shader, projectionName);
        this->modelLoc = glGetUniformLocation(shader, modelName);
        
        lastShader = shader;
   }

    // Check if texture has changed, and bind new texture if it has
    if (mesh.lastTexture != texture) {
        glBindTexture(GL_TEXTURE_2D, texture);
        mesh.lastTexture = texture;
    }

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &model[0][0]);

    if (mesh.updateQueued) {
        glBindBuffer(GL_ARRAY_BUFFER, mesh.vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, mesh.vertexSize(), mesh.toVertexArray(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.elementBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indexSize(), mesh.toElementArray(), GL_STATIC_DRAW);
        
        mesh.updateQueued = false;
    }

    unsigned int size = 3;

    size += mesh.hasTextureCoords ? 2 : 0;
    size += mesh.hasNormals ? 3 : 0;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, size * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
 
    if (mesh.hasTextureCoords) {
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, size * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    if (mesh.hasNormals) {
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, size * sizeof(float), (void*)(5 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }

    unsigned int vertexCount = mesh.indices.size();

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.elementBuffer);
    glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);

    // unsigned int vertexCount = mesh.data.size() / size;
    // glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}
}