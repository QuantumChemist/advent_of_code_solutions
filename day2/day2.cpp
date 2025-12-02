#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>

// Returns true if n has any repeating digit
bool hasRepeatingDigits(long long n) {
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
        long long total_sum = 0;
        while (std::getline(ss, value, ',')) {
            std::stringstream value_ss(value);
            long long a, b;
            char dash;
            value_ss >> a >> dash >> b;
            int count = 0;
            long long sum = 0;
            for (long long i = a; i <= b; ++i) {
                if (hasRepeatingDigits(i)) {
                    count++;
                    sum += i;
                }
            }
            total_sum += sum;
            std::cout << value << " has " << count << (count == 1 ? " invalid ID" : " invalid IDs") << " with a total sum of " << sum << "." << std::endl;
        }
        std::cout << "Total sum of invalid IDs in line: " << total_sum << std::endl;
    }
    
    infile.close();
    return 0;
}