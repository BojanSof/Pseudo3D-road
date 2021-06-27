#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <Object.hpp>
#include <SFML/Graphics.hpp>

namespace Pseudo3D {

class Segment : public Object {
public:
    Segment(float x = 0.0f, float y = 0.0f, float z = 0.0f, 
            float length = 200.0f, float width = 2000.0f,
            float curve = 0.0f);

    float getLength() const;
    float getWidth() const;
    float getCurve() const;

    void setLength(float length);
    void setWidth(float width);
    void setCurve(float curve);
private:
    float length;
    float width;
    float curve;
};

}

#endif //SEGMENT_HPP