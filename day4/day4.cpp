#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>

int main() {
    std::ifstream infile("day4.txt");
    std::string line;
    std::vector<std::string> grid;

    // Read each line into the vector
    while (std::getline(infile, line)) {
        grid.push_back(line);
    }
    infile.close();
    return 0;
}