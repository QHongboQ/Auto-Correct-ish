#ifndef WORD_H
#define WORD_H

#include <Malena/Graphics/Text.h>

class Word : public sf::Text {
private:
    int priority;
    
public:
    Word(const std::string& text, const sf::Font& font, unsigned int size, int priority);
    void setPriority(int p);
    float getPriority() const;
};

#endif // WORD_H