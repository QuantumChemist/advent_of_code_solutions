#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("day1.txt");
    std::string line;
    int starting_value = 50;
    int zero_count = 0;
        int prev_value = starting_value;
        while (std::getline(infile, line)) {
            int step = 0;
            if (line[0] == 'R') {
                step = std::stoi(line.substr(1));
                starting_value += step;
                starting_value = (starting_value + 100) % 100;
            } else if (line[0] == 'L') {
                step = -std::stoi(line.substr(1));
                starting_value += step;
                starting_value = (starting_value + 100) % 100;
            }
            // Count how many times we pass by 0
            int temp = prev_value;
            for (int i = 1; i <= std::abs(step); ++i) {
                temp = (temp + (step > 0 ? 1 : -1) + 100) % 100;
                if (temp == 0) {
                    zero_count++;
                }
            }
            prev_value = starting_value;
    }
    std::cout << "Final value: " << starting_value << std::endl;
    std::cout << "Number of times value was 0: " << zero_count << std::endl;
    infile.close();
    return 0;
}