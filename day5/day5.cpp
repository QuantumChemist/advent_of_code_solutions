#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <algorithm>


int main() {
    std::ifstream infile("day5.txt");
    if (!infile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }
    std::string line;
    std::vector<std::string> fresh_ingredients;
    std::vector<long long> available_ingredients;

    // Read fresh ingredients (ranges) until empty line
    while (std::getline(infile, line)) {
        if (line == "") {
            break;
        }
        fresh_ingredients.push_back(line);
    }
    
    // Read available ingredients (single numbers) after empty line
    while (std::getline(infile, line)) {
        if (std::find(fresh_ingredients.begin(), fresh_ingredients.end(), line) != fresh_ingredients.end()) {
            continue; // Skip entries that were already recorded as fresh ingredient ranges
        }
        if (line == "") {
            continue;
        }
        available_ingredients.push_back(std::stoll(line));
    }

    std::cout << "Fresh Ingredients:" << std::endl;
    for (const auto& ingredient : fresh_ingredients) {
        std::cout << ingredient << std::endl;
    }   
    std::cout << "Available Ingredients:" << std::endl;
    for (const auto& quantity : available_ingredients) {
        std::cout << quantity << std::endl;
    }

    infile.close();
    return 0;
}