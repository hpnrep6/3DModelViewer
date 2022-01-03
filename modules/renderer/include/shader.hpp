#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "glUtils.hpp"

namespace JRenderer {

class Shader {

    public:

    unsigned int shader = DEFAULT_START_SHADER_VALUE;

    // Shader variable names for MVP matrices
    std::string projectionName = "uProjection";
    std::string viewName = "uView";
    std::string modelName = "uModel";

    // 3 coords + 2 texture coords + 3 normal coords
    int verticeSize = 8;

    Shader(const char* vertexFile, const char* fragmentFile);
    Shader(std::string vertexSource, std::string fragmentSource);
    Shader();

    ~Shader();

    private:

    static const unsigned int DEFAULT_START_SHADER_VALUE = -1;
};

}

#endif