#include <Road.hpp>
#include <Utility.hpp>
#include <Configuration.hpp>

Pseudo3D::Road::Road() {}

size_t Pseudo3D::Road::getLength() const {
    return segments.size();
}

void Pseudo3D::Road::addSegment(size_t nEnter, size_t nHold, size_t nLeave, float curve, float hill) {
    float z = segments.size() * Pseudo3D::Configuration::roadSegLen;
    size_t i;
    for(i = 0; i < nEnter; i++) {
        segments.push_back(Segment( 0.0f, 
                                    Pseudo3D::easeInOut(0, hill, static_cast<float>(i)/nEnter), 
                                    z + i*Pseudo3D::Configuration::roadSegLen, 
                                    Pseudo3D::Configuration::roadSegLen,
                                    Pseudo3D::Configuration::roadWidth,
                                    Pseudo3D::easeIn(0, curve, static_cast<float>(i)/nEnter)));
    }
    for(; i < nEnter + nHold; i++) {
        segments.push_back(Segment( 0.0f,
                                    hill, 
                                    z + i*Pseudo3D::Configuration::roadSegLen,
                                    Pseudo3D::Configuration::roadSegLen,
                                    Pseudo3D::Configuration::roadWidth,
                                    curve));
    }
    for(; i < nEnter + nHold + nLeave; i++) {
        segments.push_back(Segment( 0.0f,
                                    Pseudo3D::easeInOut(hill, 0, static_cast<float>(i-nEnter-nHold)/nLeave),
                                    z + i*Pseudo3D::Configuration::roadSegLen, 
                                    Pseudo3D::Configuration::roadSegLen, 
                                    Pseudo3D::Configuration::roadWidth, 
                                    Pseudo3D::easeOut(curve, 0, static_cast<float>(i-nEnter-nHold)/nLeave)));
    }
}

void Pseudo3D::Road::randomRoad() {
    unsigned int nSegments = rng.randUInt(  Pseudo3D::Configuration::roadSegmentsMin, 
                                            Pseudo3D::Configuration::roadSegmentsMax);
    float curve, hill;
    size_t enter, hold, leave;
    for(size_t i = 0; i < nSegments; i++) {
        enter = rng.randUInt(   Pseudo3D::Configuration::enterLengthMin,
                                Pseudo3D::Configuration::enterLengthMax);
        hold = rng.randUInt(    Pseudo3D::Configuration::holdLengthMin,
                                Pseudo3D::Configuration::holdLengthMax);
        leave = rng.randUInt(   Pseudo3D::Configuration::leaveLengthMin,
                                Pseudo3D::Configuration::leaveLengthMax);
        curve = (rng.randUInt(0, 1)) ? rng.randFloat(Pseudo3D::Configuration::curveMin, Pseudo3D::Configuration::curveMax) : 0.0f;
        hill = (rng.randUInt(0, 1)) ? Pseudo3D::Configuration::roadSegLen * rng.randFloat(Pseudo3D::Configuration::hillMin, Pseudo3D::Configuration::hillMax) : 0.0f;
        addSegment(enter, hold, leave, curve, hill);
    }
}

const Pseudo3D::Segment& Pseudo3D::Road::operator[](size_t i) const {
    return segments[i];
}