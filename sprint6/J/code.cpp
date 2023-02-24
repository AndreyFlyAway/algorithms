#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

/*
Дан ациклический ориентированный граф (так называемый DAG, directed 
acyclic graph). Найдите его топологическую сортировку, то есть выведите
его вершины в таком порядке, что все рёбра графа идут слева направо. 
У графа может быть несколько подходящих перестановок вершин. Вам надо 
найти любую топологическую сортировку.

Формат ввода
В первой строке даны два числа – количество вершин n (1 ≤ n ≤ 105) и 
количество рёбер m (0 ≤ m ≤ 105). В каждой из следующих m строк описаны 
рёбра по одному на строке. Каждое ребро представлено парой вершин (from, 
to), 1≤ from, to ≤ n, соответственно номерами вершин начала и конца.

Формат вывода
Выведите номера вершин в требуемом порядке.

Examples:
5 3
3 2
3 4
2 5

res:
1 3 2 4 5

6 3
6 4
4 1
5 1

res:
2 3 5 6 4 1

4 0
res:
1 2 3 4
*/

std::vector<int> split_string(const std::string &expr_in) {
    std::vector<int> res;
    std::istringstream iss(expr_in);
    std::string item;
    while ( getline(iss, item, ' ' ) ) {
        res.push_back(std::stoi(item));
    }
    return res;
}

std::vector<std::vector<int>> read_graph(int v_num, int e_num) {
    std::string in_val;
    std::vector<std::vector<int>> values(v_num+1, std::vector<int> {});
    for(int i = 0 ; i < e_num + 1; ++i) {
        getline(std::cin, in_val);
        std::vector<int> vals = split_string(in_val); 
        if (vals.size() >= 2) {
            values[vals[0]].push_back(vals[1]);
        }
    }
    // for(int i = 1 ; i < e_num + 1 ; ++i) {
    //     std::sort(values[i].begin(), values[i].end());
    // }
    return values;
}

void dfs(int vertex,
        std::vector<std::vector<int>> &graph,
        std::unordered_map<int, int> &colores,
        std::vector<int> &res) {
    colores[vertex] = GRAY;
    res.push_back(vertex);

    // for(int i = graph[vertex].size() - 1 ; i >= 0 ; --i) {
    for(int i = 0 ; i < graph[vertex].size() ; ++i) {
        if(colores[graph[vertex][i]] == WHITE) {
            dfs(graph[vertex][i], graph, colores, res);
        } 
    }
    colores[vertex] = BLACK;
}

int main() {
    int v_num = -1, e_num = -1, start = 1;
    std::cin >> v_num >> e_num;
    std::vector<int> res;

    std::vector<std::vector<int>> graph = read_graph(v_num, e_num);
    std::unordered_map<int, int> colores;
    for (int i = 0 ; i < v_num + 1 ; ++i) {
        colores[i] = WHITE;
    }
    for(int i = 1 ; i < v_num + 1 ; ++i) {
        if(colores[i] == WHITE) {
            // if(graph[i].size() == 0) {
            //     res.push_back(i);
            //     colores[i] = BLACK;
            // } else {
                dfs(i, graph, colores, res);
            // }
        }
    }
    for(int i = 0 ; i < res.size()  ; ++i) {
        std::cout << res[i] << " " ;
    }
    std::cout << std::endl;
}