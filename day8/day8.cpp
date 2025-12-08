#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>


int main() {
    std::ifstream infile("day8.txt");
    std::string line;
    std::vector<std::vector<long long>> junction_box;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::vector<long long> row;
        long long number;
        while (iss >> number) {
            row.push_back(number);
        }
        junction_box.push_back(row);
    }
    infile.close();

    return 0;
}