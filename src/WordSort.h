#ifndef WORDSORT_H
#define WORDSORT_H

#include <vector>
#include <algorithm>
#include <string>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include "Word.h"
#include "FileReader.h"

class WordSort{
private:
    std::vector<Word> words;
    sf::Vector2f position;
    sf::Font font;
    void updatePositions();
    

public:
    explicit WordSort(const std::string& filename);
    void prioritize(const std::string& input);
    void setPosition(const sf::Vector2f& pos);
    void render(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

   
};

#endif // WORDSORT_H
