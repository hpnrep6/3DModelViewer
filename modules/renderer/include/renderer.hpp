#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <vector>
#include "camera.hpp"
#include "mesh.hpp"
#include "glUtils.hpp"
#include <glm/glm.hpp>

namespace JRenderer {

class Renderer {

    public:

    unsigned int viewLoc;
    unsigned int projectionLoc;
    unsigned int modelLoc;

    Renderer();
    
    static void clear();

    static void init();

    virtual void render(Camera &camera, JRenderer::Mesh &mesh, unsigned int texture);
};
}

#endif