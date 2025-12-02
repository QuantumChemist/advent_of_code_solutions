#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("day2.txt");
    std::string line;

    while (std::getline(infile, line)) {
        // IDs are separated by commas
        std::size_t comma_pos = line.find(',');
    }
    
    infile.close();
    return 0;
}