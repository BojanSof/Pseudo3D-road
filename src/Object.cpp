#include <Object.hpp>

Pseudo3D::Object::Object(float x, float y, float z) : x(x), y(y), z(z) { }

float Pseudo3D::Object::getX() const {
    return x;
}

float Pseudo3D::Object::getY() const {
    return y;
}

float Pseudo3D::Object::getZ() const {
    return z;
}

void Pseudo3D::Object::setX(float x) {
    this->x = x;
}

void Pseudo3D::Object::setY(float y) {
    this->y = y;
}

void Pseudo3D::Object::setZ(float z) {
    this->z = z;
}