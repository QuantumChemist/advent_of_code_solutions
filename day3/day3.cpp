#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>

int main() {
    std::ifstream infile("day3.txt");
    std::string line;
    long long total_sum = 0;

    while (std::getline(infile, line)) {
        int max_joltage = 0;
        for (size_t i = 0; i < line.size() - 1; ++i) {
            for (size_t j = i + 1; j < line.size(); ++j) {
                int val = (line[i] - '0') * 10 + (line[j] - '0');
                if (val > max_joltage) {
                    max_joltage = val;
                }
            }
        }
        std::cout << "max_joltage: " << max_joltage << std::endl;
        total_sum += max_joltage;
    }

    std::cout << "Total sum of battery joltage: " << total_sum << std::endl;
    infile.close();
    return 0;
}