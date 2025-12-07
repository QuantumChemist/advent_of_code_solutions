#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>


int main() {
    std::ifstream infile("day7.txt");
    std::string line;
    long long splitter_count = 0;

    while (std::getline(infile, line)) {
    // we count the number of ^ charcters in each line
        for (char c : line) {
            if (c == '^') {
                splitter_count++;
            }
        }
    }
    infile.close();

    return 0;
}