#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>

// Returns true if n has any repeating digit
bool hasRepeatingDigits(int n) {
    std::string s = std::to_string(n);
    if (s.size() % 2 != 0) return false;
    std::string first = s.substr(0, s.size() / 2);
    std::string second = s.substr(s.size() / 2);
    return first == second;
}

int main() {
    std::ifstream infile("day2.txt");
    std::string line;

    while (std::getline(infile, line)) {
        // IDs are separated by commas
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            std::stringstream value_ss(value);
            int a, b;
            char dash;
            value_ss >> a >> dash >> b;
            int sum = 0;
            for (int i = a; i <= b; ++i) {
                if (hasRepeatingDigits(i)) {
                    sum++;
                }
            }
            std::cout << value << " has sum of  invalid IDs" << sum << (sum == 1 ? "" : "s") << "." << std::endl;
        }
    }
    
    infile.close();
    return 0;
}