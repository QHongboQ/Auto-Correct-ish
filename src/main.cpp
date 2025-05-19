#include <SFML/Graphics.hpp>
#include <Malena/Graphics/TextInput.h>
#include <Malena/Traits/Stateful.h>
#include "WordSort.h"

int main() {
    ml::CustomTextInput userInput;

    userInput.enableState(ml::Stateful::ENABLED);
    userInput.setPosition({100, 100});

    WordSort ws("5000-baby-girl-names.txt");
    ws.setPosition({200, 200});

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1000, 500), 32), "Auto-Correct-ish");


    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            userInput.eventHandler(window, *event);

            if (event->is<sf::Event::TextEntered>())
                ws.prioritize(userInput.getText());
        }
        
        window.clear();
        window.draw(userInput);
        ws.render(window);
        window.display();
    }

    return 0;
}
