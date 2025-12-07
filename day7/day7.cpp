#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits>
#include <cctype>
#include <array>
#include <stack>


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

    // Part 1: Classical splitting (previous solution)
    // ...existing code...

    // Part 2: Quantum splitting (many-worlds)
    // Each timeline is a unique path; we want to count unique end positions in the last row
    std::set<std::pair<int, int>> quantum_visited; // (row, col) per timeline
    std::set<int> end_columns; // columns reached in last row
    std::stack<std::pair<int, int>> stack;
    stack.push({start_row + 1, start_col});

    while (!stack.empty()) {
        auto [r, c] = stack.top();
        stack.pop();
        if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
        // Each timeline can revisit a cell, but not the same (row,col) in the same timeline
        if (quantum_visited.count({r, c})) continue;
        quantum_visited.insert({r, c});

        char cell = grid[r][c];
        if (r == rows - 1) {
            end_columns.insert(c);
            continue;
        }
        if (cell == '^') {
            // Split: left and right
            if (c - 1 >= 0) stack.push({r + 1, c - 1});
            if (c + 1 < cols) stack.push({r + 1, c + 1});
        } else if (cell == '.' || cell == 'S') {
            stack.push({r + 1, c});
        }
        // Ignore other characters
    }

    std::cout << "Total number of quantum timelines (unique end positions): " << end_columns.size() << std::endl;
    return 0;
}