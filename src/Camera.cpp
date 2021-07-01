#include <Camera.hpp>
#include <cmath>

Pseudo3D::Camera::Camera(float x, float y, float z, float FOV) : Object(x, y, z), FOV(FOV) {
    d = 1/tan(0.5 * FOV * M_PI / 180);
}

std::tuple<float, float, float> Pseudo3D::Camera::project(const Segment &seg, const Object &player, float w, float h) {
    // translate the segment center, realtive to the camera
    float x_translated = seg.getX() - x - player.getX();
    float y_translated = seg.getY() - y;
    float z_translated = seg.getZ() - z;
    // project the points on normalised screen plane
    float x_proj = x_translated * d / z_translated;
    float y_proj = y_translated * d / z_translated;
    float w_proj = seg.getWidth() * d / z_translated;
    // scale the coordinates
    float x_screen = (w/2) * (1 + x_proj);
    float y_screen = (h/2) * (1 - y_proj);
    float w_screen = (w/2) * w_proj;
    return std::make_tuple(x_screen, y_screen, w_screen);
}

float Pseudo3D::Camera::getFOV() const {
    return FOV;
}

float Pseudo3D::Camera::getDepth() const {
    return d;
}

void Pseudo3D::Camera::setFOV(float FOV) {
    this->FOV = FOV;
    d = 1/tan(0.5 * FOV * M_PI / 180);
}