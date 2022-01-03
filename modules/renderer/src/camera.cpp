#include "camera.hpp"
#include <algorithm>
#include <iostream>
namespace JRenderer {

const float PITCH_LIMIT = M_PI / 2.0f - 0.01f;

Camera::Camera(float width, float height) :
    width {width},
    height {height} {

    this->updateMatrices();
}

void Camera::updateMatrices() {
    // Projection matrix
    this->projection = glm::perspective(glm::radians(this->fieldOfView), this->width / this->height, this->near, this->far);

    // View matrix
    this->view = glm::lookAt(this->location, this->location + this->front, this->up);
}

void Camera::setLocation(float x, float y, float z) {
    this->location.x = x;
    this->location.y = y;
    this->location.z = z;
}

void Camera::offsetLocation(float x, float y, float z) {
    this->location.x += x;
    this->location.y += y;
    this->location.z += z;
}

void Camera::moveForward(float amount) {
    this->location += front * amount;
}

void Camera::moveRight(float amount) {
    this->location += glm::normalize(glm::cross(this->front, this->up)) * amount;
}

void Camera::moveUp(float amount) {
    glm::vec3 left = -glm::normalize(glm::cross(this->front, this->up));

    
    this->location += glm::normalize(glm::cross(this->front, left)) * amount;
}

void Camera::updatePitchAndYaw(float pitch, float yaw) {
    this->pitch = pitch;
    this->yaw = yaw;

   // Clamp pitch between PITCH_LIMIT and -PITCH_LIMIT
    this->pitch = std::min(PITCH_LIMIT, this->pitch);
   
    this->pitch = std::max(-PITCH_LIMIT, this->pitch);

    this->front.x = cos(yaw) * cos(this->pitch);
    this->front.y = sin(this->pitch);
    this->front.z = sin(yaw) * cos(this->pitch);

    this->front = glm::normalize(this->front);
}

void Camera::offsetPitchAndYaw(float pitch, float yaw) {
    this->updatePitchAndYaw(this->pitch + pitch, this->yaw + yaw);
}

void Camera::updateFOV(float fov) {
    this->fieldOfView = fov;
}

void Camera::offsetFOV(float fov) {
    this->fieldOfView += fov;

    this->fieldOfView = std::max(0.0001f, fov);
}

void Camera::resize(float width, float height) {
    this->width = width;
    this->height = height;
}

}