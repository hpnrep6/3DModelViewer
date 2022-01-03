#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "camera.hpp"
#include "glUtils.hpp"
#include "renderer.hpp"
#include "window.hpp"
#include "shader.hpp"
#include "mesh.hpp"

using namespace JRenderer;

class Viewer: public Window {
    public:

    JRenderer::Mesh *mesh;
    unsigned int texture;
    
    JRenderer::Shader *shaderProgram;

    bool firstMouse = true;
    int lastX = 0, lastY = 0;

    Viewer(const char* obj, const char* image, const char* vert, const char* frag): Window(800, 800, "Viewer") {
        mesh = JRenderer::Mesh::createFromFile(obj);
        shaderProgram = new JRenderer::Shader(vert, frag);

        mesh->material.shader = *shaderProgram;

        texture = JRenderer::createImageTexture(image);

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        this->camera.moveForward(-5.0f);
        this->camera.moveUp(3.0f);
    }

    void update(float delta) {
        captureInput(delta);
        renderer.clear();
        camera.updateMatrices();
        renderer.render(camera, *mesh, texture);
    }

    void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
        if (firstMouse) {
            lastX = xpos; lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX,
              yoffset = lastY - ypos;
        lastX = xpos; lastY = ypos;
        xoffset *= .1f; yoffset *= .1f;
    
        camera.offsetPitchAndYaw(yoffset /  60.f, xoffset / 60.f);
    }

    void captureInput(float delta) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        float cameraSpeed = 2.5 * delta;

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera.moveForward(cameraSpeed);

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera.moveForward(-cameraSpeed);

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            camera.moveRight(-cameraSpeed);
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera.moveRight(cameraSpeed);

        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
            camera.moveUp(cameraSpeed);

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
            camera.moveUp(-cameraSpeed);
    }
};

int main(int argc, char **argv) {

    Window::init();

    std::string objPath = "../sample.obj";
    std::string vertPath = "../shader.vert";
    std::string fragPath = "../shader.frag";
    std::string imgPath = "../sample.png";

    if (argc >= 2) {
        objPath = std::string(argv[1]);
    }

    if (argc >= 3) {
        imgPath = std::string(argv[2]);
    }

    if (argc >= 5) {
        vertPath = std::string(argv[3]);
        fragPath = std::string(argv[4]);
    }

    Viewer test = Viewer(objPath.c_str(), imgPath.c_str(), vertPath.c_str(), fragPath.c_str());

    test.startLoop();

    Window::terminate();

    return 0;

}