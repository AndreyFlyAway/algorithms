/*
Задан неориентированный граф. Обойдите поиском в ширину все вершины,
достижимые из заданной вершины s, и выведите их в порядке обхода, если 
начинать обход из s.

Формат ввода
В первой строке дано количество вершин n (1 ≤ n ≤ 105) и рёбер 
m (0 ≤ m ≤ 105). Далее в m строках описаны рёбра графа. Каждое ребро 
описывается номерами двух вершин u и v (1 ≤ u, v ≤ n). В последней 
строке дан номер стартовой вершины s (1 ≤ s ≤ n).

Гарантируется, что в графе нет петель и кратных рёбер.

Формат вывода
Выведите вершины в порядке обхода, считая что при запуске от каждой 
конкретной вершины её соседи будут рассматриваться в порядке возрастания
(то есть если вершина 2 соединена с 1 и 3, то сначала обход пойдёт в 1, 
а уже потом в 3).

Examples:

4 4
1 2
2 3
3 4
1 4
3

res:
3 2 4 1 

2 1
2 1
1

res:
1 2 

6 6
4 2
4 1
5 1
2 3
5 6
2 6
6

res:
6 2 5 3 4 1 

6 6
4 5
6 3
2 6
1 3
2 4
6 4
2

res:
2 4 6 5 3 1

10 11
1 9
10 4
3 9
3 7
2 5
8 6
8 4
3 6
1 4
5 3
7 1
9

res:
9 1 3 4 7 5 6 8 10 2 

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
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
    while (getline(iss, item, ' ')) {
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
            auto it_second = values.find(vals[1]);
            if(it_second != values.end()) {
                values[vals[1]].push_back(vals[0]);
            } else {
                values[vals[1]] = std::vector<int> {vals[0]};
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

std::vector<int> bfs(int start, int v_num, 
                     std::unordered_map<int, std::vector<int>> &graph,
                     std::unordered_map<int, int> &colores) {
    std::vector<int> res {start};
    std::deque<int> planed {start};
    colores[start] = GRAY;
    while (!planed.empty())
    {
        int cur_index = planed.front();
        planed.pop_front();
        for(int i = 0 ; i < graph[cur_index].size() ; ++i) {
            if(colores[graph[cur_index][i]] == WHITE) {
                res.push_back(graph[cur_index][i]);
                colores[graph[cur_index][i]] = GRAY;
                planed.push_back(graph[cur_index][i]);
            }
        }
        colores[cur_index] = BLACK;
    }
    return res;
}

int main() {
    int v_num = -1, e_num = -1, start = -1;
    std::cin >> v_num >> e_num;
    std::unordered_map<int, std::vector<int>> graph = read_graph(v_num, e_num);
    std::unordered_map<int, int> colores;
    for (auto& it: graph) {
        colores[it.first] = WHITE;
    }
    std::cin >> start;
    std::vector<int> res = bfs(start, v_num, graph, colores);
    // std::cout << "RES: ";
    for(int i = 0 ; i < res.size()  ; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}