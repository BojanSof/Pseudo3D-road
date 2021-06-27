#include <Random.hpp>

Pseudo3D::Random::Random() : randomEngine(std::random_device()()){}

unsigned int Pseudo3D::Random::randUInt(unsigned int low, unsigned int high){
    std::uniform_int_distribution<unsigned int> dist(low, high);
    return dist(randomEngine);
}

unsigned int Pseudo3D::Random::randUInt(unsigned int high){
    return randUInt(0, high);
}

float Pseudo3D::Random::randFloat(float low, float high) {
    std::uniform_real_distribution<float> dist(low, high);
    return dist(randomEngine);
}

float Pseudo3D::Random::randFloat(float high) {
    return randFloat(0.0f, high);
}