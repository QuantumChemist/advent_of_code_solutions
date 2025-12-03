#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>

int main() {
    std::ifstream infile("day3.txt");
    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        long long joltage = 0;
        long long total_sum = 0;
        int curr = 0;
        int prev = 0;

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            curr = static_cast<int>(c - '0');
            if (curr > prev) {
                std::cout << "prev: " << prev << " curr: " << curr << std::endl;
            }
        }
        total_sum += joltage;
        std::cout << "Total sum of battery joltage: " << total_sum << std::endl;

    }
    
    infile.close();
    return 0;
}