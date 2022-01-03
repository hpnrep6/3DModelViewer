#include "glUtils.hpp"

namespace JRenderer {

unsigned int createImageTexture(unsigned char *data, GLenum format, GLenum filter, GLenum wrap, const int width, const int height) {
    unsigned int texture;
    
    // create texture
    glGenTextures(1, &texture);

    // set texture as currently bounded texture in opengl
    glBindTexture(GL_TEXTURE_2D, texture);
    
    // set texture wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);

    // set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);

    // create texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    return texture;
}

unsigned int createImageTexture(unsigned char *data, GLenum format, const int width, const int height) {
    return createImageTexture(data, format, GL_LINEAR, GL_REPEAT, width, height);
}

unsigned int createImageTexture(unsigned char *data, const int width, const int height) {
    return createImageTexture(data, GL_RGBA, GL_LINEAR, GL_REPEAT, width, height);
}

unsigned int createImageTexture(const char *fileName, GLenum filter, GLenum wrap) {
    int width, height, channel;

    unsigned int format;

    unsigned char *data = stb::stbi_load(fileName, &width, &height, &channel, stb::STBI_rgb_alpha);

#ifndef RELEASE
    if(stb::stbi_failure_reason()) {

        //JRenderer::error("Error occured during loading of image file: " + std::string(fileName) + ". Error: " + std::string(stb::stbi_failure_reason()));
    } 
#endif

    if (data) {

        unsigned int texture = createImageTexture(data, GL_RGBA, filter, wrap, width, height);

        stb::stbi_image_free(data);

        return texture;
        
    } else {
        //JRenderer::error("Failed loading image file: " + std::string(fileName));
        stb::stbi_image_free(data);
        return 0;
    }
}

unsigned int createImageTexture(std::string fileName, GLenum filter, GLenum wrap) {
    return createImageTexture((JRenderer::FILE_PREFIX_TO_ROOT_DIR + fileName).c_str(), filter, wrap);
}

unsigned int createImageTexture(std::string &fileName) {
    return createImageTexture(fileName, GL_LINEAR, GL_REPEAT);
}

unsigned int createImageTexture(const char* fileName) {
    std::string string = std::string(fileName);
    return createImageTexture(string);
}

unsigned int createShaderProgram(const char *vertexShader, const char *fragmentShader) {
    
    // Create and compile shaders
    unsigned int vertShader = compileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fragShader = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    // Initialise shader program
    unsigned int program = glCreateProgram();

    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

#ifndef RELEASE
    GLint linked = 0;

    glGetProgramiv(program, GL_LINK_STATUS, &linked);

    // Log error if program linking failed
    if(linked == GL_FALSE) {
        GLint length = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

        char error[length];
        glGetProgramInfoLog(program, length, &length, error);

        glDeleteProgram(program);

        //JRenderer::error("Shader program compilation error:\n" + std::string(error));

        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
        return 0;
    }
#endif

    // Shaders will no longer be used; remove them.
    glDetachShader(program, vertShader);
    glDetachShader(program, fragShader);

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
}

unsigned int createShaderProgram(const std::string vertexShader, const std::string fragmentShader) {
    return createShaderProgram(vertexShader.c_str(), fragmentShader.c_str());
}

unsigned int compileShader(const char *shaderSource, GLenum shaderType) {
    unsigned int shader = glCreateShader(shaderType);

    glShaderSource(shader, 1, &shaderSource, NULL);

    glCompileShader(shader);

#ifndef RELEASE
    GLint compiled = 0;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    // If shader compilation failed, print out error
    if(compiled == GL_FALSE) {
        GLint length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

        char error[length];

        glGetShaderInfoLog(shader, length, &length, error);

        //JRenderer::error("Shader program compilation error:\n\n" + std::string(error) + "\nShader source code:\n" + std::string(shaderSource));

        glDeleteShader(shader);
        return 0;
    }
#endif

    return shader;
}

std::string loadTextFile(const std::string filePath) {
    std::string finalPath = FILE_PREFIX_TO_ROOT_DIR + filePath;

    // Reference https://stackoverflow.com/questions/18398167/how-to-copy-a-txt-file-to-a-char-array-in-c
    std::ifstream stream(finalPath);
    std::string text((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

    return text;
}

}