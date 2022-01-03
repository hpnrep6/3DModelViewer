#ifndef GLUTILS_H
#define GLUTILS_H

#include <string>
#include <iostream>
#include <GL/glew.h>
#include <stb/stb_image.h>
#include <string>
#include <fstream>

#define IMAGE_LOAD_ERROR 0x00;

namespace JRenderer {

const std::string FILE_PREFIX_TO_ROOT_DIR = "";

unsigned int createImageTexture(unsigned char *data, GLenum format, GLenum filter, GLenum wrap, const int width, const int height);

unsigned int createImageTexture(unsigned char *data, GLenum format, const int width, const int height);

unsigned int createImageTexture(unsigned char *data, const int width, const int height);

unsigned int createImageTexture(const char *fileName, GLenum filter, GLenum wrap);

unsigned int createImageTexture(const char *fileName);

unsigned int createImageTexture(std::string &fileName);

unsigned int createShaderProgram(const char *vertexShader, const char *fragmentShader);

unsigned int createShaderProgram(const std::string vertexShader, const std::string fragmentShader);

unsigned int compileShader(const char *shaderSource, GLenum shaderType);

std::string loadTextFile(const std::string filePath);

}

#endif