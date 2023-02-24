#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/*
Алла пошла на стажировку в студию графического дизайна, где ей дали такое задание:
для очень большого числа ориентированных графов преобразовать их список рёбер в 
список смежности. Чтобы побыстрее решить эту задачу, она решила автоматизировать 
процесс.

Помогите Алле написать программу, которая по списку рёбер графа будет строить 
его список смежности.

Формат ввода
В первой строке дано число вершин n (1 ≤ n ≤ 100) и число ребер m (1 ≤ m ≤ n(n-1)).
В следующих m строках заданы ребра в виде пар вершин (u,v), если ребро ведет от u
к v.

Формат вывода
Выведите информацию о рёбрах, исходящих из каждой вершины.

В строке i надо написать число рёбер, исходящих из вершины i, а затем перечислить
вершины, в которые ведут эти рёбра –— в порядке возрастания их номеров

examples:
in:
5 3
1 3
2 3
5 2

out:
1 3 
1 3 
0 
0 
1 2 

10 55
1 3
1 5
1 6
1 9
1 10
2 5
2 7
2 8
2 10
3 1
3 6
3 7
4 1
4 2
4 3
4 5
4 7
4 8
4 10
5 3
5 4
5 6
5 7
5 8
5 9
5 10
6 1
6 2
6 3
6 5
6 8
6 9
6 10
7 1
7 3
7 8
8 1
8 2
8 3
8 4
8 5
8 6
8 7
8 9
9 2
9 4
9 5
9 6
9 8
10 1
10 2
10 4
10 5
10 6
10 7

res:
5 3 5 6 9 10 
4 5 7 8 10 
3 1 6 7 
7 1 2 3 5 7 8 10 
7 3 4 6 7 8 9 10 
7 1 2 3 5 8 9 10 
3 1 3 8 
8 1 2 3 4 5 6 7 9 
5 2 4 5 6 8 
6 1 2 4 5 6 7 

*/

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

int main() {
    int v_num = -1, e_num = -1;
    std::string in_val;
    std::cin >> v_num >> e_num;
    std::vector<std::vector<int>> values(v_num+1, std::vector<int> {0});
    for(int i = 0 ; i < e_num + 1 ; ++i) {
        getline(std::cin, in_val);
        std::vector<int> vals = split_string(in_val); 
        // for(int j = 0 ; j < vals.size() ; ++j) {
        //     std::cout << vals[j] << " ";
        //     std::cout << std::endl;
        // }
        // std::cout << vals.size() << std::endl;
        if (vals.size() >= 2) {
            values[vals[0]][0] += 1;
            values[vals[0]].push_back(vals[1]);
        }
    }
    for (int i = 1 ; i < values.size() ; ++i) {
        for(int j = 0 ; j < values[i].size() ; ++j) {
            std::cout << values[i][j] << " ";
        }
        std::cout << std::endl;
    }
}