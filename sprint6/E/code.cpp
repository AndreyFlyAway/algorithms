/*
Вам дан неориентированный граф. Найдите его компоненты связности.

Формат ввода
В первой строке дано количество вершин n (1≤ n ≤ 105) и рёбер m
(0 ≤ m ≤ 2 ⋅ 105). В каждой из следующих m строк записано по ребру в виде 
пары вершин 1 ≤ u, v ≤ n.

Гарантируется, что в графе нет петель и кратных рёбер.

Формат вывода
Выведите все компоненты связности в следующем формате: в первой строке 
выведите у количество компонент. Затем на отдельных строках выведите вершины каждой 
компоненты, отсортированные по возрастанию номеров. Компоненты между собой
упорядочивайте по номеру первой вершины.

Examples:
6 3
1 2
6 5
2 3

res: 
3
1 2 3 
4 
5 6 

2 0
res:
2
1 
2 

4 3
2 3
2 1
4 3

res:
1
1 2 3 4 

10 7
2 1
5 8
5 3
9 6
1 9
6 10
7 2

res:
3
1 2 6 7 9 10 
3 5 8 
4

*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
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

std::vector<std::vector<int>> read_graph(int v_num, int e_num) {
    std::string in_val;
    std::vector<std::vector<int>> values(v_num+1, std::vector<int> {});
    for(int i = 0 ; i < e_num + 1 ; ++i) {
        getline(std::cin, in_val);
        std::vector<int> vals = split_string(in_val);
        if(vals.size() == 2) {
            values[vals[0]].push_back(vals[1]);
            values[vals[1]].push_back(vals[0]);

        }
    }
    // for(std::vector<int> &v : values) {
    //     std::sort(v.begin(), v.end());
    // }
    return values;
}


int dfs(int start,
        std::vector<std::vector<int>> &graph,
        std::vector<std::vector<int>> &res) {
    static std::vector<int> colores(graph.size()+1, -1);
    std::vector<int> cur_branch{};
    std::vector<int> stack {start};
    static int component_count {1};
    if (colores[start] != -1) {
        return component_count;
    }
    while (!stack.empty())
    {
        int cur_vertex = stack.back(); 
        stack.pop_back();
        
        if(colores[cur_vertex] == -1) {
            colores[cur_vertex] = GRAY;
            stack.push_back(cur_vertex);
            cur_branch.push_back(cur_vertex);
            for(int i = graph[cur_vertex].size() - 1 ; i >= 0 ; --i) {
                if (colores[graph[cur_vertex][i]] == -1) {
                    stack.push_back(graph[cur_vertex][i]);
                }
            }
        } else {
            colores[cur_vertex] = component_count;
        }
    }
    ++component_count;
    std::sort(cur_branch.begin(), cur_branch.end());
    res.push_back(cur_branch);
    return component_count;
}

void print_res(std::vector<std::vector<int>> &res) {
    std::cout << res.size() << std::endl;
    for(int i = 0 ; i < res.size() ; ++i) {
        for(int j : res[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int v_num = -1, e_num = -1, start = 1;
    std::cin >> v_num >> e_num;
    // std::vector<int> colores(v_num+1, -1);
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> graph = read_graph(v_num, e_num);
    for(int i = 1 ; i < v_num + 1 ; ++i) {
        dfs(i, graph, res);
    }
    print_res(res);
}