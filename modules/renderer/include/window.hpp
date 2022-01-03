#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "camera.hpp"
#include "renderer.hpp"

namespace JRenderer {

class Window {
    
    public: 

    int width = 900, height = 900;

    GLFWwindow* window;
    Camera camera = Camera(width, height);
    Renderer renderer = Renderer();

    static void init();
    static void terminate();

    Window(int width, int height, const char* name);
    Window();
    ~Window();

    void startLoop();
    void stopLoop();

    void setAsCurrent();

    virtual void mouseCallback(GLFWwindow* window, double xLoc, double yLoc);
    virtual void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
    virtual void resizeCallback(GLFWwindow* window, int width, int height);

    virtual void update(float delta);
    
    private:

    float lastUpdateTime = 0.0f;
    bool continueLoop = true;
};

}

#endif