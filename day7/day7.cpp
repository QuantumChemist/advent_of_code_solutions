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
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <numeric>
#include <optional>
#include <variant>
#include <cassert>
#include <chrono>
#include <random>

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
    std::set<int> end_columns; // columns reached in last row

    // Recursive DFS function
    std::function<void(int, int)> dfs = [&](int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return;
        char cell = grid[r][c];
        if (r == rows - 1) {
            end_columns.insert(c);
            return;
        }
        if (cell == '^') {
            // Split: left and right
            if (c - 1 >= 0) dfs(r + 1, c - 1);
            if (c + 1 < cols) dfs(r + 1, c + 1);
        } else if (cell == '.' || cell == 'S') {
            dfs(r + 1, c);
        }
        // Ignore other characters
    };

    dfs(start_row + 1, start_col);

    std::cout << "Total number of quantum timelines (unique end positions): " << end_columns.size() << std::endl;
    return 0;
}

// giving up lol