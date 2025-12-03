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
            total_sum += joltage;
        
        
        std::cout << "Total sum of battery joltage: " << total_sum << std::endl;
    }
    
    infile.close();
    return 0;
}