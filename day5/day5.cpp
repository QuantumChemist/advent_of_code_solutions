#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

// Checking Last Merged Interval – O(n*log(n)) Time and O(n) Space
std::vector<std::vector<int>> mergeOverlap(std::vector<std::vector<int>>& arr) {

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());
  
    std::vector<std::vector<int>> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        std::vector<int>& last = res.back();
        std::vector<int>& curr = arr[i];

        // If current interval overlaps with the last merged
        // interval, merge them 
        if (curr[0] <= last[1]) 
            last[1] = std::max(last[1], curr[1]);
        else 
            res.push_back(curr);
    }

    return res;
}


int main() {
    std::ifstream infile("day5.txt");
    if (!infile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }
    std::string line;
    std::vector<std::string> fresh_ingredients;
    std::vector<long long> available_ingredients;
    long long fresh_sum = 0;
    long long total_fresh = 0;
    std::vector<std::vector<int>> intervals;

    while (std::getline(infile, line)) {
        if (line == "") {
            break;
        }
        fresh_ingredients.push_back(line);
    }
    
    while (std::getline(infile, line)) {
        if (std::find(fresh_ingredients.begin(), fresh_ingredients.end(), line) != fresh_ingredients.end()) {
            continue; // Skip entries that were already recorded as fresh ingredient ranges
        }
        if (line == "") {
            continue;
        }
        available_ingredients.push_back(std::stoll(line));
    }

    // Check which available ingredients fall within any fresh ingredient range
    for (const auto& quantity : available_ingredients) {
        for (const auto& range : fresh_ingredients) {
            std::stringstream ss(range);
            long long a, b;
            char dash;
            ss >> a >> dash >> b;
            if (quantity >= a && quantity <= b) {
                fresh_sum++;
                break;
            }
        }
    }

    std::cout << "Fresh Ingredients:" << std::endl;
    for (const auto& ingredient : fresh_ingredients) {
        std::cout << ingredient << std::endl;
    }   
    std::cout << "Available Ingredients:" << std::endl;
    for (const auto& quantity : available_ingredients) {
        std::cout << quantity << std::endl;
    }

    std::cout << "Total sum of fresh ingredients: " << fresh_sum << std::endl;

    for (const auto& range : fresh_ingredients) {
    std::stringstream ss(range);
    long long a, b;
    char dash;
    ss >> a >> dash >> b;
    intervals.push_back({static_cast<int>(a), static_cast<int>(b)});
}

    infile.close();
    return 0;
}