#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <queue>


int main() {
    std::ifstream infile("day7.txt");
    std::vector<std::string> grid;
    std::string line;
    int start_row = -1, start_col = -1;

    // Read the grid and find 'S'
    while (std::getline(infile, line)) {
        grid.push_back(line);
    }
    infile.close();

    int rows = grid.size();
    int cols = grid.empty() ? 0 : grid[0].size();
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 'S') {
                start_row = r;
                start_col = c;
            }
        }
    }
    if (start_row == -1 || start_col == -1) {
        std::cout << "No start position S found." << std::endl;
        return 1;
    }

    // BFS for beams: each beam is (row, col)
    std::queue<std::pair<int, int>> beams;
    std::set<std::pair<int, int>> visited; // To avoid duplicate beams at same spot
    beams.push({start_row + 1, start_col}); // Start beam below S
    long long split_count = 0;

    while (!beams.empty()) {
        auto [r, c] = beams.front();
        beams.pop();
        // Out of bounds
        if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
        // Already visited this cell with a beam
        if (visited.count({r, c})) continue;
        visited.insert({r, c});

        char cell = grid[r][c];
        if (cell == '^') {
            split_count++;
            // Split left and right, continue downward from those positions
            if (c - 1 >= 0) beams.push({r + 1, c - 1});
            if (c + 1 < cols) beams.push({r + 1, c + 1});
        } else if (cell == '.' || cell == 'S') {
            // Continue downward
            beams.push({r + 1, c});
        }
        // Ignore other characters
    }

    std::cout << "Total number of splits: " << split_count << std::endl;
    return 0;
}