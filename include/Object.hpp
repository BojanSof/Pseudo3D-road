#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace Pseudo3D{

class Object {
public:
    Object(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float x);
    void setY(float y);
    void setZ(float z);
protected:
    float x, y, z; //Object's center world coordinates
};

}

#endif //OBJECT_HPP