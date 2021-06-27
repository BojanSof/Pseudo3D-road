#ifndef APP_HPP
#define APP_HPP

#include <Segment.hpp>
#include <Camera.hpp>
#include <Quad.hpp>
#include <Road.hpp>
#include <SFML/Graphics.hpp>
#include <array>
#include <string>

namespace Pseudo3D {

class App {
public:
    App();
    ~App();

    bool isRunning() const;
    void reset();
    void handleEvents();
    void update(/*const sf::Time &dt*/);
    void display();

    void run();

private:
    std::string title;
    sf::RenderWindow window;
    sf::Clock clock;
    bool running, redraw;
    Object player;
    Camera cam;
    Quad qGrass, qRoad, qRumble, qRoadLine;
    Road road;
    float delta;
};

}

#endif //APP_HPP