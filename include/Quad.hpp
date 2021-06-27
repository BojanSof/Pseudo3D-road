#ifndef QUAD_HPP
#define QUAD_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Color.hpp>

namespace Pseudo3D {
/*******************************************
QUAD parameters:
            <--w2-->
                (x2,y2)
                   |
            ***************
           *               *
          *                 *
         *                   *
        *                     *
       ************************* 
                   |
                (x1,y1)
       <-----w1---->         

********************************************/
class Quad : public sf::Drawable{
    public:
        Quad(   float x1 = 0.0f, float x2 = 0.0f, 
                float y1 = 0.0f, float y2 = 0.0f, 
                float w1 = 0.0f, float w2 = 0.0f,
                const sf::Color &color = sf::Color::White);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        float getX1() const;
        float getX2() const;
        float getY1() const;
        float getY2() const;
        float getW1() const;
        float getW2() const;
        const sf::Color& getColor() const;

        void setXYWc(   float x1, float x2, 
                        float y1, float y2, 
                        float w1, float w2,
                        const sf::Color &color);
        void setXYW(float x1, float x2, 
                    float y1, float y2, 
                    float w1, float w2);
        void setX1(float x1);
        void setX2(float x2);
        void setY1(float y1);
        void setY2(float y2);
        void setW1(float w1);
        void setW2(float w2);

    protected:
        void updateShape();
        
        float x1, x2;
        float y1, y2;
        float w1, w2;
        sf::Color color;
        sf::ConvexShape shape;
};

}

#endif //QUAD_HPP