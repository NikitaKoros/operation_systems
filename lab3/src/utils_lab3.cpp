#include "../include/utils_lab3.hpp"

bool is_valid(std::string line) {
    return !line.empty() && std::isupper(line[0]);
}