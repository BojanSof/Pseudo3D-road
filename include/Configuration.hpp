#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

namespace Pseudo3D {

namespace Configuration {
    extern unsigned int width, height;
    extern float roadWidth, roadSegLen;
    extern float camHeight, camHeightMin, camHeightMax;
    extern float FOV, FOVMin, FOVMax, dFOV;
    extern float delta, deltaMin, deltaMax, dDelta;
    extern float speed, speedMin, speedMax, dSpeed;
    extern size_t drawDistance, drawDistanceMin, drawDistanceMax;
    
    extern unsigned int FPS;

    extern unsigned int roadSegmentsMin, roadSegmentsMax;
    extern size_t enterLengthMin, enterLengthMax;
    extern size_t holdLengthMin, holdLengthMax;
    extern size_t leaveLengthMin, leaveLengthMax;
    extern float curveMin, curveMax;
    extern float hillMin, hillMax;

    void loadConfig(const std::string &fname);
}
/*
class Configuration {
public:
    Configuration();

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    float getRoadLength() const;
    float getRoadWidth() const;
    float getRoadSegLen() const;
    size_t getNumSeg() const;
    size_t getDrawDistance() const;


    void setWidth(unsigned int w);
    void setHeight(unsigned int h);
    void setRoadLength(float length);
    void setRoadWidth(float width);
    void setRoadSegLen(float length);

    void setNumSeg(size_t n);
    void setDrawDistance(size_t dist);

private:
    unsigned int width, height;
    float roadWidth, roadSegLen;
    size_t numSeg;
    size_t drawDistance;
};
*/
}

#endif //CONFIGURATION_HPP