#include "WordSort.h"

WordSort::WordSort(const std::string& filename) {
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        exit(1);
    }

    FileReader fileReader{filename};
    const auto& wordsFromFile = fileReader.getWords();

    for (const auto& word : wordsFromFile) {
        words.emplace_back(word, font, 20, 0);
    }
}

void WordSort::setPosition(const sf::Vector2f& pos) {
    position = pos;
    updatePositions();
}

void WordSort::updatePositions() {
    sf::Vector2f currentPos = position;
    for (int i = 0; i < std::min(5, (int)words.size()); ++i) {
        words[i].setPosition(currentPos);
        currentPos.y += 30;
    }
}

void WordSort::prioritize(const std::string& input) {
    for (auto& word : words) {
        if (word.getString().find(input) != std::string::npos) {
            word.setPriority(1);
        } else {
            word.setPriority(0);
        }
    }

    std::sort(words.begin(), words.end(), [](const Word& a, const Word& b) {
        return a.getPriority() > b.getPriority();
    });

    updatePositions();
}

void WordSort::render(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < std::min(5, (int)words.size()); ++i) {
        target.draw(static_cast<const sf::Text&>(words[i]), states);

    }
}
