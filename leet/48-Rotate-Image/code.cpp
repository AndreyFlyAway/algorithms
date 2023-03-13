/*
3 3
1 2 3
1 2 3
1 2 3

1 1 1
2 2 2
3 3 3

4 4 
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4

*/

#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& matrix) {
    
}

void print(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}