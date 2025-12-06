#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>

// bro, I barely got part one without Copilot, part two will be shamelessly with Copilot 


int main() {
    std::ifstream infile("day6.txt");
    std::string line;
    std::vector<std::vector<int>> grid;
    std::vector<std::string> operations;
    std::vector<long long> result;
    std::string ops;
    int count = 0;
    long long total = 0;

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
            result[col] = 0;
        }
        if (operations[col] == "*") {
            result[col] = 1;
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

    for (const auto& res : result) {
        total += res;
    }
    std::cout << "Total: " << total << std::endl;

    part_two();

    return 0;
}

void part_two() {

    std::vector<std::string> number_lines;
    std::string operator_line;

    std::ifstream infile("day6.txt");
    std::string line;
    while (std::getline(infile, line)) {
        number_lines.push_back(line);
    }
    infile.close();

    if (!number_lines.empty()) {
        operator_line = number_lines.back();
        number_lines.pop_back(); // Remove operator line from number_lines
    }

    int nrows = number_lines.size();
    int ncols = number_lines[0].size();
    std::vector<std::string> columns(ncols);

    for (int col = 0; col < ncols; ++col) {
        std::string col_str;
        for (int row = 0; row < nrows; ++row) {
            col_str += number_lines[row][col];
        }
        columns[col] = col_str;
    }
    
}