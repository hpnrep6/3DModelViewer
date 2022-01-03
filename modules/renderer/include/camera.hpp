#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>

namespace JRenderer {

class Camera {

    public: 

    glm::vec3 
    location = glm::vec3(0.0f, 0.0f, 0.0f),
    front = glm::vec3(0.0f, 0.0f, -1.0f),
    up = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::mat4
    projection,
    view;

    float
    yaw = -M_PI / 2.0f, // ~ -90 degrees
    pitch = 0.0f,
    roll = 0.0f,
    fieldOfView = 45.0f,
    near = 0.05f,
    far = 5000.0f,

    width,
    height;

    Camera(float width, float height);

    void updateMatrices();

    void setLocation(float x, float y, float z);

    void offsetLocation(float x, float y, float z);

    void moveForward(float amount);

    void moveRight(float amount);

    void moveUp(float amount);

    void updatePitchAndYaw(float yaw, float pitch);

    void offsetPitchAndYaw(float yaw, float pitch);

    void updateFOV(float fov);

    void offsetFOV(float fovOffset);

    void resize(float width, float height);
};

}

#endif