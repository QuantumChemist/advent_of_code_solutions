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
        std::string result = "";
        size_t n = line.size();
        size_t start = 0;
        int digits_to_pick = 12;
        for (int d = 0; d < digits_to_pick; ++d) {
            // Remaining digits to pick: digits_to_pick - d
            // Search window: start to n - (digits_to_pick - d)
            char max_digit = '0';
            size_t max_pos = start;
            for (size_t i = start; i <= n - (digits_to_pick - d); ++i) {
                if (line[i] > max_digit) {
                    max_digit = line[i];
                    max_pos = i;
                }
            }
            result += max_digit;
            start = max_pos + 1;
        }
        std::cout << "max_joltage: " << result << std::endl;
        total_sum += std::stoll(result);
    }

    std::cout << "Total sum of battery joltage: " << total_sum << std::endl;
    infile.close();
    return 0;
}