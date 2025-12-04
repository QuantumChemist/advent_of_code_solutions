#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>

int check_neighbors(const std::vector<std::string>& grid, int x, int y) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    // Directions for 8 neighbors
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];

        // Check bounds
        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
            if (grid[newX][newY] == '@') {
                count++;
            }
        }
    }

    return count;
}

int main() {
    std::ifstream infile("day4.txt");
    std::string line;
    std::vector<std::string> grid;
    std::vector<std::string> rm_grid;
    long total_papers = 0;

    // Read each line into the vector
    while (std::getline(infile, line)) {
        grid.push_back(line);
    }
    infile.close();

    int rows = grid.size();           // number of rows
    int cols = grid[0].size();        // number of columns
    rm_grid = grid;  // Copy grid first

    while (true) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '@') {
                    if (check_neighbors(grid, i, j) < 4) {
                        total_papers++;
                        rm_grid[i][j] = '-'; // mark for removal
                    }
                }
            }
        }

        grid = rm_grid;
    }
 
   // boi i suck....

    std::cout << "Total papers with less than 4 neighboring '@': " << total_papers << std::endl;

    return 0;
}