#include <Quad.hpp>

Pseudo3D::Quad::Quad(   float x1, float x2, 
                        float y1, float y2, 
                        float w1, float w2,
                        const sf::Color &color
                    ) : x1(x1), x2(x2), 
                        y1(y1), y2(y2),
                        w1(w1), w2(w2),
                        color(color),
                        shape(4) { 
    updateShape();
}

void Pseudo3D::Quad::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape, states);
}

float Pseudo3D::Quad::getX1() const {
    return x1;
}
float Pseudo3D::Quad::getX2() const {
    return x2;
}
float Pseudo3D::Quad::getY1() const {
    return y1;
}
float Pseudo3D::Quad::getY2() const {
    return y2;
}
float Pseudo3D::Quad::getW1() const {
    return w1;
}
float Pseudo3D::Quad::getW2() const {
    return w2;
}
const sf::Color &Pseudo3D::Quad::getColor() const {
    return color;
}

void Pseudo3D::Quad::setXYWc(   float x1, float x2, 
                                float y1, float y2, 
                                float w1, float w2,
                                const sf::Color &color) {
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    this->w1 = w1;
    this->w2 = w2;
    this->color = color;
    updateShape();
}

void Pseudo3D::Quad::setXYW(float x1, float x2, 
                            float y1, float y2, 
                            float w1, float w2) {
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    this->w1 = w1;
    this->w2 = w2;
    updateShape();
}

void Pseudo3D::Quad::setX1(float x1) {
    this->x1 = x1;
    updateShape();
}

void Pseudo3D::Quad::setX2(float x2) {
    this->x2 = x2;
    updateShape();
}

void Pseudo3D::Quad::setY1(float y1) {
    this->y1 = y1;
    updateShape();
}

void Pseudo3D::Quad::setY2(float y2) {
    this->y2 = y2;
    updateShape();
}

void Pseudo3D::Quad::setW1(float w1) {
    this->w1 = w1;
    updateShape();
}

void Pseudo3D::Quad::setW2(float w2) {
    this->w2 = w2;
    updateShape();
}

void Pseudo3D::Quad::updateShape() {
    shape.setFillColor(color);
    shape.setPoint(0, sf::Vector2f(x1 - w1, y1));
    shape.setPoint(1, sf::Vector2f(x2 - w2, y2));
    shape.setPoint(2, sf::Vector2f(x2 + w2, y2));
    shape.setPoint(3, sf::Vector2f(x1 + w1, y1));
}