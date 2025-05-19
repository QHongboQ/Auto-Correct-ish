#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

class FileReader {
private:
    std::vector<std::string> words;

public:
    FileReader(const std::string& filename);
    const std::vector<std::string>& getWords() const;
};

#endif // FILEREADER_H