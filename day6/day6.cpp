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
    std::vector<std::string> operations;


    // Read each line into the vector
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::stringstream ss_line(line);
        int num;
        std::string ops;
        std::vector<int> row;
        
        // Extract first 4 space-separated numbers from ss
        for (int i = 0; i < 5 && ss >> num && ss_line >> ops; i++) {
            row.push_back(num);
            if (i == 4) {
                operations.push_back(ops);
            }
        }
        
        // Add the row to the grid
        grid.push_back(row);
    }
    infile.close();
    

    std::cout << grid[3][3] << std::endl;
    std::cout << operations[3] << std::endl;

    return 0;
}