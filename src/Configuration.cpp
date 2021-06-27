#include <Configuration.hpp>

unsigned int Pseudo3D::Configuration::width = 800;
unsigned int Pseudo3D::Configuration::height = 600;

float Pseudo3D::Configuration::roadWidth = 2500.0f;
float Pseudo3D::Configuration::roadSegLen = 250.0f;

float Pseudo3D::Configuration::camHeight = 1800.0f;
float Pseudo3D::Configuration::camHeightMin = 500.0f;
float Pseudo3D::Configuration::camHeightMax = 5000.0f;

float Pseudo3D::Configuration::FOV = 100.0f;
float Pseudo3D::Configuration::FOVMin = 60.0f;
float Pseudo3D::Configuration::FOVMax = 140.0f;

float Pseudo3D::Configuration::delta = Pseudo3D::Configuration::roadSegLen;
float Pseudo3D::Configuration::deltaMin = 0.25f*Pseudo3D::Configuration::roadSegLen;
float Pseudo3D::Configuration::deltaMax = 2.0f*Pseudo3D::Configuration::roadSegLen;

size_t Pseudo3D::Configuration::drawDistance = 100;
size_t Pseudo3D::Configuration::drawDistanceMin = 200;
size_t Pseudo3D::Configuration::drawDistanceMax = 50;

unsigned int Pseudo3D::Configuration::FPS = 60;

unsigned int Pseudo3D::Configuration::roadSegmentsMin = 3;
unsigned int Pseudo3D::Configuration::roadSegmentsMax = 10;
size_t Pseudo3D::Configuration::enterLengthMin = 30;
size_t Pseudo3D::Configuration::enterLengthMax = 100;
size_t Pseudo3D::Configuration::holdLengthMin = 150;
size_t Pseudo3D::Configuration::holdLengthMax = 500;
size_t Pseudo3D::Configuration::leaveLengthMin = 30;
size_t Pseudo3D::Configuration::leaveLengthMax = 100;
float Pseudo3D::Configuration::curveMin = -10.0f;
float Pseudo3D::Configuration::curveMax = 10.0f;
float Pseudo3D::Configuration::hillMin = -60.0f;
float Pseudo3D::Configuration::hillMax = 60.0f;

void Pseudo3D::Configuration::loadConfig(const std::string &fname) {}
/*
Pseudo3D::Configuration::Configuration() {}

unsigned int Pseudo3D::Configuration::getWidth() const {
    return width;
}

unsigned int Pseudo3D::Configuration::getHeight() const {
    return height;
}

float Pseudo3D::Configuration::getRoadWidth() const {
    return roadWidth;
}

float Pseudo3D::Configuration::getRoadSegLen() const {
    return roadSegLen;
}

size_t Pseudo3D::Configuration::getNumSeg() const {
    return numSeg;
}

size_t Pseudo3D::Configuration::getDrawDistance() const {
    return drawDistance;
}

void Pseudo3D::Configuration::setWidth(unsigned int w) {
    width = w;
}

void Pseudo3D::Configuration::setHeight(unsigned int h) {
    height = h;
}

void Pseudo3D::Configuration::setRoadWidth(float width) {
    roadWidth = width;
}

void Pseudo3D::Configuration::setRoadSegLen(float length) {
    roadSegLen = length;
}

void Pseudo3D::Configuration::setNumSeg(size_t n) {
    numSeg = n;
}

void Pseudo3D::Configuration::setDrawDistance(size_t dist) {
    drawDistance = dist;
}
*/