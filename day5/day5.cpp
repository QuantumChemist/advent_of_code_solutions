#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>


int main() {
    std::ifstream infile("day5.txt");
    std::string line;
    std::vector<std::string> fresh_ingredients;
    std::vector<int> available_ingredients;

    while (std::getline(infile, line)) {
        int i;
        for (i = 0; i < line.size(); i++) {
            fresh_ingredients[i] = line;
            }
            if (line == "") {
                break;
        }
        for (; i < line.size(); i++) {
            available_ingredients[i - fresh_ingredients.size()] = std::stoi(line);
        }
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