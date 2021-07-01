#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <Object.hpp>
#include <Segment.hpp>
#include <tuple>

namespace Pseudo3D{

class Camera : public Object {
public:
    Camera(float x = 0.0f, float y = 0.0f, float z = 0.0f, float FOV = 100.0f);

    float getFOV() const;
    float getDepth() const;

    void setFOV(float FOV);

    std::tuple<float, float, float> project(const Segment &seg, const Object &player, float w, float h);
private:
    float FOV; //Field Of View in degrees
    float d; //Camera distance from screen (normalised), also called depth
};

}

#endif //CAMERA_HPP