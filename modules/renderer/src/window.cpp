#include "window.hpp"

namespace {
bool initialised = false;
}

JRenderer::Window* current;

void callMouseCallback(GLFWwindow* window, double xLoc, double yLoc) {
    current->mouseCallback(window, xLoc, yLoc);
}

void callScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    current->scrollCallback(window, xOffset, yOffset);
}

void callResizeCallback(GLFWwindow* window, int width, int height) {
    current->resizeCallback(window, width, height);
}

namespace JRenderer {

void Window::init() {
    if (initialised) {
        return;
    }

    glewExperimental = true;

    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    initialised = true;
}

void Window::terminate() {
    glfwTerminate();
    current = nullptr;
}

Window::Window(int width, int height, const char* name) {
    Window::init();

    this->width = width;
    this->height = height;

    this->window = glfwCreateWindow(width, height, name, NULL, NULL);

#ifndef RELEASE
    if (this->window == NULL) {
        //il6::error("Error creating window with name " + std::string(name));
        glfwTerminate();
        return;
    }
#endif

    glfwMakeContextCurrent(this->window);
    glewInit();

    // Must be called after glewInit
    Renderer::init();

    glfwSetFramebufferSizeCallback(this->window, callResizeCallback);
    glfwSetCursorPosCallback(this->window, callMouseCallback);
    glfwSetScrollCallback(this->window, callScrollCallback);

    setAsCurrent();
}

Window::Window(): Window(this->width, this->height, "Window") {

}

Window::~Window() {
    glfwDestroyWindow(window);
}

void Window::mouseCallback(GLFWwindow* window, double xLoc, double yLoc) {

}

void Window::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {

}

void Window::resizeCallback(GLFWwindow* window, int width, int height) {
    this->camera.resize(width, height);
}

void Window::startLoop() {
    glfwMakeContextCurrent(window);
    this->setAsCurrent();

    lastUpdateTime = glfwGetTime();

    while (continueLoop && !glfwWindowShouldClose(window)) {
        // Get change in time
        float now = glfwGetTime();
        float delta = now - lastUpdateTime;
        lastUpdateTime = now;

        this->update(delta);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::stopLoop() {
    continueLoop = false;
}

void Window::setAsCurrent() {
    current = this;
}

void Window::update(float delta) {
    // Default empty update function
}
}