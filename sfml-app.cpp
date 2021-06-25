// for normal use g++ filename.cpp

// always compile using g++ -c FILENAME.cpp
// then 
// g++ FILENAME.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
// then run ./sfml-app


#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}