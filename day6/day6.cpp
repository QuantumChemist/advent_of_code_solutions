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
    std::vector<long long> result;
    std::string ops;
    int count = 0;

    // Read each line into the vector
    while (std::getline(infile, line)) {
        count++;
        std::stringstream ss(line);
        int num;
        std::vector<int> row;

        while ( ss >> num) {
                row.push_back(num);
        }    
        grid.push_back(row);

        if (count > 4) {
            ops = ss.str();
        }
    }
    infile.close(); 

    std::stringstream opss(ops);
    std::string operation; 
    while (opss >> operation) {
        operations.push_back(operation);
    }

    result.resize(operations.size());

    for (int col = 0; col < operations.size(); col++) {
        if (operations[col] == "+") {
            result[col] += 0;
        }
        if (operations[col] == "*") {
            result[col] *= 1;
        }
    }

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (operations[col] == "+") {
                result[col] += grid[row][col];
            }
            if (operations[col] == "*") {
                result[col] *= grid[row][col];
            }
        }
    }

    std::cout << grid[2][3] << std::endl; 
    std::cout << operations[3] << std::endl;
    std::cout << result[2] << std::endl;

    return 0;
}