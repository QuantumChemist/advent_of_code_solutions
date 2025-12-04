#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>

int main() {
    std::ifstream infile("day4.txt");
    std::string line;
    std::vector<std::string> grid;

    // Read each line into the vector
    while (std::getline(infile, line)) {
        grid.push_back(line);
    }
    infile.close();

    int rows = grid.size();           // number of rows
    int cols = grid[0].size();        // number of columns

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '@') {
                // This is a roll of paper, check its neighbors
            }
        }
    }
 
   // boi i suck....

    return 0;
}