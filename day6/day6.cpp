#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>


int main() {
    std::ifstream infile("day6.txt");
    std::string line;
    std::vector<std::vector<int>> grid;

    // Read each line into the vector
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        int num;
        std::vector<int> row;
        std::vector<int> throwaway;

        while ( ss >> num) {
                row.push_back(num);
        }    
        grid.push_back(row);
    }
    infile.close();
    
    // Print the grid to verify
    for (const auto& row : grid) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }   

    std::cout << grid[3][8] << std::endl; 

    return 0;
}