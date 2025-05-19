#include "FileReader.h"

FileReader::FileReader(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << '\n';
        return;
    }

    std::string line;
    
    while (std::getline(file, line)) {
        if (!line.empty()) {
            words.push_back(line);
        }
    }

    file.close();
}

const std::vector<std::string>& FileReader::getWords() const {
    return words;
}
