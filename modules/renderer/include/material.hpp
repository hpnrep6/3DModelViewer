#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/glew.h>
#include <string>
#include "shader.hpp"

namespace JRenderer {

class Material {

    public:

    JRenderer::Shader shader;
    
    unsigned int texture = -1;
};
}

#endif