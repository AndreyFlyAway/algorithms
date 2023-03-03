
#include <iostream>
#include <vector>
#include <string>

int compress(std::vector<char>& data) {
    int n = data.size();
    if (n == 1) {
        return 1;
    }
    int j = 0, i = 0;
    for(; i < n ; i++) {
        int count = 1;
        for(; i < (n - 1) && data[i] == data[i+1];  ++count, ++i) {}
        data[j++] = data[i];
        if(count > 1) {
            for(char c: std::to_string(count)) {
                data[j++] = c; 
            }
        }

    }
    return j;
}

int main() {
    std::string in;
    std::cin >> in;
    std::vector<char> data(in.begin(), in.end());
    std::cout << compress(data) << std::endl;
}