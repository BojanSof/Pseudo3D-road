#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdlib>
#include <ctime>
#include <random>

namespace Pseudo3D{

class Random{
public:
    Random();

    unsigned int randUInt(unsigned int low, unsigned int high);
    unsigned int randUInt(unsigned int high);
    float randFloat(float low, float high);
    float randFloat(float high);
private:
    std::mt19937 randomEngine;
};

}

#endif //RANDOM_HPP
