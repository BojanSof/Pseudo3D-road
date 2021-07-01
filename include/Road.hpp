#ifndef ROAD_HPP
#define ROAD_HPP

#include <Segment.hpp>
#include <Configuration.hpp>
#include <Random.hpp>
#include <vector>

namespace Pseudo3D {

class Road {
public:
    Road();

    size_t getLength() const;
    void addSegment(size_t nEnter, size_t nHold, size_t nLeave, float curve, float hill);
    void randomRoad();

    const Segment& operator[](size_t i) const;
private:
    std::vector<Segment> segments;
    Random rng;
};

}

#endif //ROAD_HPP