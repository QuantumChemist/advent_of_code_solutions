#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("day2.txt");
    std::string line;

    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}