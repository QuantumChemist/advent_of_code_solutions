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
        std::string joltage_str = "";
        long long joltage = 0;
        long long total_sum = 0;
        int curr = 0;
        int prev = 0;
        int prev2 = 0;
        int curr_i = 0;
        int prev_i = 0;
        int prev2_i = 0;

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            curr = static_cast<int>(c - '0');
            curr_i = i;
            if (curr > prev) {
                prev = curr;
                prev_i = curr_i;
            } else if (i > prev_i && curr > prev2) {
                prev2 = curr;
                prev2_i = curr_i;
            }
            joltage_str = line[prev_i] + line[prev2_i];
        }
        std::cout << "joltage_str: " << joltage_str << std::endl;
        total_sum += joltage;
        std::cout << "Total sum of battery joltage: " << total_sum << std::endl;

    }
    
    infile.close();
    return 0;
}