#include "Word.h"

Word::Word(const std::string& text, const sf::Font& font, unsigned int size, int priority)
    : sf::Text(font, text, size), priority(priority) {
}

void Word::setPriority(int p) {
    priority = p;
}

float Word::getPriority() const {
    return priority;
}
