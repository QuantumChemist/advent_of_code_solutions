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

    for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
        if (di == 0 && dj == 0) continue;  // Skip the cell itself
        int ni = i + di;  // neighbor row
        int nj = j + dj;  // neighbor column
        if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
            if (grid[ni][nj] == '@') {
                // Count this neighbor
            }
        }
    }
} // boi i suck....

    return 0;
}