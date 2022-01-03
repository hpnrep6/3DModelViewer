#include "shader.hpp"

namespace JRenderer {

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
#ifdef DEBUG
    std::cout<<"Shader created: " << vertexFile << ", " << fragmentFile << std::endl;
#endif
    shader = JRenderer::createShaderProgram(
        JRenderer::loadTextFile(vertexFile),
        JRenderer::loadTextFile(fragmentFile)
    );
}

Shader::Shader(std::string vertexSource, std::string fragmentSource) {
#ifdef DEBUG
    std::cout<<"Shader created: " << vertexSource << "\n-----------\n" << fragmentSource << std::endl;
#endif
    shader = JRenderer::createShaderProgram(
        vertexSource,
        fragmentSource
    );
}

Shader::Shader(): Shader("shader.vert", "shader.frag") {
#ifdef DEBUG
    std::cout<<"Shader created: default"<<std::endl;
#endif
}

Shader::~Shader() {
    if (shader != DEFAULT_START_SHADER_VALUE) {
#ifdef DEBUG
    std::cout<<"Shader deleted: " << shader << std::endl;
#endif
        glDeleteProgram(shader);
    }
}

}