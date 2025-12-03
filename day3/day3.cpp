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
        std::string joltage_str = "";
        int curr = 0;
        int prev = -1;    // largest digit
        int prev2 = -1;   // second largest digit
        int curr_i = 0;
        int prev_i = -1;  // index of largest
        int prev2_i = -1; // index of second largest

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            curr = static_cast<int>(c - '0');
            curr_i = i;
            if (curr > prev) {
                prev2 = prev;
                prev2_i = prev_i;
                prev = curr;
                prev_i = curr_i;
            } else if (curr > prev2) {
                prev2 = curr;
                prev2_i = curr_i;
            }
        }
        // Form the two-digit number in the order they appear
        if (prev_i != -1 && prev2_i != -1) {
            if (prev_i < prev2_i) {
                joltage_str = std::string() + line[prev_i] + line[prev2_i];
            } else {
                joltage_str = std::string() + line[prev2_i] + line[prev_i];
            }
            std::cout << "joltage_str: " << joltage_str << std::endl;
            total_sum += std::stoll(joltage_str);
        }
    }

    std::cout << "Total sum of battery joltage: " << total_sum << std::endl;
    infile.close();
    return 0;
}