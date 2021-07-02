#ifndef APP_HPP
#define APP_HPP

#include <Segment.hpp>
#include <Camera.hpp>
#include <Quad.hpp>
#include <Road.hpp>
#include <SFML/Graphics.hpp>
#include <array>
#include <string>
#include <sstream>

namespace Pseudo3D {

class App {
public:
    App();
    ~App();

    bool isRunning() const;
    void reset();
    void handleEvents();
    void update();
    void display();

    void run();

private:
    std::string title;
    sf::RenderWindow window;
    bool running, redraw;
    Object player;
    Camera cam;
    Quad qGrass, qRoad, qRumble, qRoadLine;
    Road road;
    float delta, speed;
    
    sf::Font font;
    sf::Text text;
    std::stringstream ss;
    bool updateText;
};

}

#endif //APP_HPP