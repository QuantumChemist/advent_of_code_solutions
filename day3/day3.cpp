#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <string>

int main() {
    std::ifstream infile("day3.txt");
    std::string line;
    long long total_sum = 0;

    while (std::getline(infile, line)) {
        int max_joltage = 0;
        for (size_t i = 0; i < line.size() - 1; ++i) {
            for (size_t j = i + 1; j < line.size(); ++j) {
                for (size_t a = j + 1; a < line.size() - 1; ++a) {
                    for (size_t b = a + 1; b < line.size(); ++b) {
                        for (size_t c = b + 1; c < line.size() - 1; ++c) {
                            for (size_t d = c + 1; d < line.size(); ++d) {
                                for (size_t e = d + 1; e < line.size() - 1; ++e) {
                                    for (size_t f = e + 1; f < line.size(); ++f) {
                                        for (size_t g = f + 1; g < line.size() - 1; ++g) {
                                            for (size_t h = g + 1; h < line.size(); ++h) {
                                                for (size_t k = h + 1; k < line.size() - 1; ++k) {
                                                    for (size_t l = k + 1; l < line.size(); ++l) {
                int val =  (line[i] - '0') * 100000000000 +  (line[j] - '0') * 10000000000 +  (line[a] - '0') * 1000000000 + (line[b] - '0') * 100000000 + (line[c] - '0') * 10000000 + (line[d] - '0') * 1000000 +  (line[e] - '0') * 100000 +  (line[f] - '0') * 10000 + (line[g] - '0') * 1000 + (line[h] - '0') * 100 + (line[k] - '0') * 10 + (line[l] - '0');
                if (val > max_joltage) {
                    max_joltage = val;
                }
                            }
        }
                    }
        }
                    }
        }
                    }
        }
                    }
        }
            }
        }
        std::cout << "max_joltage: " << max_joltage << std::endl;
        total_sum += max_joltage;
    }

    std::cout << "Total sum of battery joltage: " << total_sum << std::endl;
    infile.close();
    return 0;
}