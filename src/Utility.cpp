#include <Utility.hpp>
#include <cmath>

float Pseudo3D::easeIn(float a, float b, float p) {
    return a + (b-a)*p*p;
}

float Pseudo3D::easeOut(float a, float b, float p) {
    return a + (b-a)*(p*(2-p));
}

float Pseudo3D::easeInOut(float a, float b, float p) {
    return a + (b-a)*(-0.5f*cos(M_PI*p) + 0.5f);
}