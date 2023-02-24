#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

std::string parse_line(std::string values) {
    std::string res = "some res for: " + values;
    return res;
}

void read_file(const std::string& file_path) {
    std::ifstream infile(file_path);
    std::string line;
    int a, b;
    std::string cur_string;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        if (!(iss >> cur_string)) { break; } // TODO: error, make rising exception
        std::cout << cur_string << std::endl;
        // process pair (a,b)
    }
}

int main() {
    read_file("text.txt");
}



