#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream infile("day2.txt");
    std::string line;

    while (std::getline(infile, line)) {
        // IDs are separated by commas
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            std::stringstream value_ss(value);
            std::cout << value << std::endl;
            int a, b;
            char dash;
            value_ss >> a >> dash >> b;
            std::cout << abs(a) << std::endl;
            std::cout << abs(b) << std::endl;
        }
    }
    
    infile.close();
    return 0;
}