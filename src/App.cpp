#include <App.hpp>
#include <Configuration.hpp>
#include <iostream>
#include <iomanip>

Pseudo3D::App::App() :  title("Pseudo 3D"),
                        window(sf::VideoMode(Pseudo3D::Configuration::width, Pseudo3D::Configuration::height, 32), title),
                        running(true), redraw(true),
                        cam(0.0f, Pseudo3D::Configuration::camHeight, 0.0f, Pseudo3D::Configuration::FOV),
                        delta(Pseudo3D::Configuration::delta)
                        {
    window.setFramerateLimit(60);
    road.randomRoad();
}

Pseudo3D::App::~App() {
    window.close();
}

bool Pseudo3D::App::isRunning() const {
    return running;
}

void Pseudo3D::App::reset() {

}

void Pseudo3D::App::handleEvents() {
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                running = false;
            break;
            case sf::Event::KeyPressed:
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        running = false;
                    break;
                    default:
                    break;
                }
            }
            break;
            default:
            break;
        }    
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        cam.setX(cam.getX() - delta);
        redraw = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        cam.setX(cam.getX() + delta);
        redraw = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(cam.getY() < Pseudo3D::Configuration::camHeightMax) {
            cam.setY(cam.getY() + delta);
        }
        redraw = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if(cam.getY() > Pseudo3D::Configuration::camHeightMin) {
            cam.setY(cam.getY() - delta);
        }
        redraw = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        if(cam.getFOV() < Pseudo3D::Configuration::FOVMax)
            cam.setFOV(cam.getFOV() + 5.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if(cam.getFOV() > Pseudo3D::Configuration::FOVMin)
            cam.setFOV(cam.getFOV() - 5.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(delta < Pseudo3D::Configuration::deltaMax)
            delta += 5.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(delta > Pseudo3D::Configuration::deltaMin)
            delta -= 5.0f;
    }
}

void Pseudo3D::App::update(/*const sf::Time &dt*/) {
    redraw = true;
    cam.setZ(cam.getZ() + delta);
    if(cam.getZ() >= road.getLength() * Pseudo3D::Configuration::roadSegLen) {
        cam.setZ(cam.getZ() - road.getLength() * Pseudo3D::Configuration::roadSegLen);
    }
    if(!redraw) return;
    window.clear(sf::Color(0,146,230));
    size_t startPos = cam.getZ()/Pseudo3D::Configuration::roadSegLen;
    float x = 0.0f, dx = 0.0f;
    float camX = cam.getX(), camY = cam.getY(), camZ = cam.getZ();
    float maxY = Pseudo3D::Configuration::height;
    cam.setY(camY + road[(startPos) % road.getLength()].getY());
    for(size_t i = startPos + 1; i < startPos + Pseudo3D::Configuration::drawDistance; i++) {
        const Segment &prev = road[(i - 1) % road.getLength()];
        const Segment &curr = road[i % road.getLength()];


        dx += curr.getCurve();
        x += dx;
        if(i-1 >= road.getLength())
            cam.setZ(camZ - road.getLength()*Pseudo3D::Configuration::roadSegLen);
        cam.setX(camX-(x-dx));
        auto prevProjection = cam.project(prev, player, Pseudo3D::Configuration::width, Pseudo3D::Configuration::height);
        if(i >= road.getLength())
            cam.setZ(camZ - road.getLength()*Pseudo3D::Configuration::roadSegLen);
        cam.setX(camX-x);
        auto currProjection = cam.project(curr, player, Pseudo3D::Configuration::width, Pseudo3D::Configuration::height);
        if( std::get<2>(currProjection) <= cam.getDepth() ||
            std::get<1>(currProjection) >= maxY) {
            continue;
        }
        maxY = std::get<1>(currProjection);
        sf::Color roadColor = ((i/3)%2) ? sf::Color(100,100,100) : sf::Color(120,120,120);
        sf::Color grassColor = ((i/3)%2) ? sf::Color(0,168,0) : sf::Color(0,190,0);
        sf::Color rumbleColor = ((i/3)%2) ? sf::Color::Red : sf::Color::White;
        sf::Color roadLineColor = ((i/3)%2) ? sf::Color(101,103,100) : sf::Color::White;

        qGrass.setXYWc( 0.5f * Pseudo3D::Configuration::width, 0.5f * Pseudo3D::Configuration::width,
                        std::get<1>(prevProjection), std::get<1>(currProjection),
                        0.5f * Pseudo3D::Configuration::width, 0.5f * Pseudo3D::Configuration::width,
                        grassColor);
        qRumble.setXYWc(std::get<0>(prevProjection), std::get<0>(currProjection),
                        std::get<1>(prevProjection), std::get<1>(currProjection),
                        1.1f * std::get<2>(prevProjection), 1.1f * std::get<2>(currProjection),
                        rumbleColor);
        qRoad.setXYWc(  std::get<0>(prevProjection), std::get<0>(currProjection),
                        std::get<1>(prevProjection), std::get<1>(currProjection),
                        std::get<2>(prevProjection), std::get<2>(currProjection),
                        roadColor);
        qRoadLine.setXYWc(  std::get<0>(prevProjection), std::get<0>(currProjection),
                            std::get<1>(prevProjection), std::get<1>(currProjection),
                            0.02f * std::get<2>(prevProjection), 0.02f * std::get<2>(currProjection),
                            roadLineColor);
        window.draw(qGrass);
        window.draw(qRumble);
        window.draw(qRoad);
        window.draw(qRoadLine);
    }
    cam.setX(camX);
    cam.setY(camY);
    cam.setZ(camZ);
    redraw = false;
}

void Pseudo3D::App::display() {
    window.display();
}

void Pseudo3D::App::run() {
    //sf::Time timeSinceLastUpdate;
    //sf::Time timePerFrame = sf::seconds(1.f/Pseudo3D::Configuration::FPS);
    while(isRunning()) {
        //timeSinceLastUpdate += clock.restart();
        //while(timeSinceLastUpdate > timePerFrame) {
        //    timeSinceLastUpdate -= timePerFrame;
        handleEvents();
        update(/*timePerFrame*/);
    // }
        display();
    }
}