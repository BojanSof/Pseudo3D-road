#include <Segment.hpp>

Pseudo3D::Segment::Segment( float x, float y, float z, 
                            float length, float width,
                            float curve) : Object(x, y, z), length(length), width(width), curve(curve) { }

float Pseudo3D::Segment::getLength() const {
    return length;
}

float Pseudo3D::Segment::getWidth() const {
    return width;
}

float Pseudo3D::Segment::getCurve() const {
    return curve;
}

void Pseudo3D::Segment::setLength(float length) {
    this->length = length;
}

void Pseudo3D::Segment::setWidth(float width) {
    this->width = width;
}

void Pseudo3D::Segment::setCurve(float curve) {
    this->curve = curve;
}