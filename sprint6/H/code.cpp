/*
Вам дан ориентированный граф. Известно, что все его вершины достижимы из вершины
s=1. Найдите время входа и выхода при обходе в глубину, производя первый запуск 
из вершины s. Считайте, что время входа в стартовую вершину равно 0. Соседей 
каждой вершины обходите в порядке увеличения номеров.

Формат ввода
В первой строке дано число вершин n (1 ≤ n ≤ 2⋅ 105) и рёбер (0 ≤ m ≤ 2 ⋅ 105). 
В каждой из следующих m строк записаны рёбра графа в виде пар (from, to), 
1 ≤ from ≤ n — начало ребра, 1 ≤ to ≤ n — его конец. Гарантируется, что в 
графе нет петель и кратных рёбер.

Формат вывода
Выведите n строк, в каждой из которых записана пара чисел tini, touti — время 
входа и выхода для вершины i.

Examples:
6 8
2 6
1 6
3 1
2 5
4 3
3 2
1 2
1 4

res:
0 11
1 6
8 9
7 10
2 3
4 5

3 2
1 2
2 3

res:
0 5
1 4
2 3
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;


std::vector<int> split_string(const std::string &expr_in) {
    // std::cout << "string in " << expr_in << std::endl;
    std::vector<int> res;
    std::istringstream iss(expr_in);
    std::string item;
    while ( getline(iss, item, ' ' ) ) {
        res.push_back(std::stoi(item));
    }
    return res;
}

std::unordered_map<int, std::vector<int>> read_graph(int v_num, int e_num) {
    std::string in_val;
    std::unordered_map<int, std::vector<int>> values;
    for(int i = 0 ; i < e_num + 1 ; ++i) {
        getline(std::cin, in_val);
        std::vector<int> vals = split_string(in_val); 
        if (vals.size() >= 2) {
        // std::cout << "got vals: " << vals[0] << " " << vals[1] << std::endl;
            auto it_first = values.find(vals[0]);
            if(it_first != values.end()) {
                values[vals[0]].push_back(vals[1]);
            } else {
                values[vals[0]] = std::vector<int> {vals[1]};
            }
        }
    }
    for(auto &it : values) {
        std::sort(it.second.begin(), it.second.end());
    }
    // for(auto &it : values) {
    //     std::cout << it.first << ": "; 
    //     for(int i : it.second) {
    //         std::cout << i << " "; 
    //     }
    //     std::cout << std::endl;
    // }
    return values;
}

void dfs(int vertex,
        std::vector<int> &entry,
        std::vector<int> &leave,
        std::unordered_map<int, std::vector<int>> &graph,
        std::unordered_map<int, int> &colores) {
    static int time = -1;
    ++time;
    entry[vertex] = time;
    colores[vertex] = GRAY;
    // for(int i = graph[vertex].size() - 1 ; i >= 0 ; --i) {
    for(int i = 0 ; i < graph[vertex].size() ; ++i) {
        if(colores[graph[vertex][i]] == WHITE) {
            dfs(graph[vertex][i], entry, leave, graph, colores);
        }
    }
    ++time;
    leave[vertex] = time;
    colores[vertex] = BLACK;
}

int main() {
    int v_num = -1, e_num = -1, start = 1;
    std::cin >> v_num >> e_num;
    std::vector<int> entry (v_num+1, 1);
    std::vector<int> leave (v_num+1, 1);

    std::unordered_map<int, std::vector<int>> graph = read_graph(v_num, e_num);
    std::unordered_map<int, int> colores;
    for (int i = 0 ; i < v_num ; ++i) {
        colores[i] = WHITE;
    }
    dfs(start, entry, leave, graph, colores);
    for(int i = 1 ; i < leave.size()  ; ++i) {
        std::cout << entry[i] << " " << leave[i] << std::endl;
    }
}