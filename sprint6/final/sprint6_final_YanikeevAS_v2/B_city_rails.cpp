/* номер посылки: 80478884 */
/*
Принцип работы:
На основе исходных данных составляется развернутый граф. Развернутый граф проверяется 
на наличие циклов при помощи поиска в ширину, если цикл есть, то в один из городов 
можно попасть по нескольким рельсам, т.е. карта не оптимальна.

Временная сложность:
O(v+e), где v - количесто узлов, e - колиечество ребер.

Пространственна сложность:
O(v*e) + O(v) - для хранения цветов в алгоитме поиска в ширину, где v - количесто узлов,
e - колиечество ребер. Итоговоая O(v*e + v) эквиваленто O(v*e), т.к. v заведомо меньше.

Доказательство коррекности:
При сооставлении развернутого графа можно получить ориентированный граф, этот граф покажет
пути ведущие из города с большим городом в меньший, это подходит для условия, т.к. будет 
проверяться доступность к каждому из городов, т.е. можно получить доступность к городу из 
несколько городов с разным типов рельсов, если к городу будет такой доступ, значит он будет 
зацикленный, это можно проверить при помощиы алгоритмом поиска в ширину.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

const char R_VAL = 'R';
const char B_VAL = 'B';


const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

using Graph = std::vector<std::vector<int>>;

Graph read_rails() {
    int v_num;
    std::cin >> v_num;
    std::string str_in;
    Graph cities(v_num+1, std::vector<int> ());
    for(int i = 0 ; i < v_num - 1; ++i) {
        std::cin >> str_in;
        for(int j = 0 ; j < str_in.size() ; ++j) {
            if (str_in[j] == B_VAL) {
                cities[i].push_back(i+j+1);
            } else if(str_in[j] == R_VAL) {
                cities[i+j+1].push_back(i);
            } 
        }
    }
    return cities;
}


bool dfs_is_cylce(int start, std::vector<std::vector<int>> &graph) {
    static std::vector<int> colores(graph.size(), WHITE);

    std::vector<int> stack {start};
    while (!stack.empty())
    {
        int cur_vertex = stack.back(); 
        stack.pop_back();
        
        if(colores[cur_vertex] == WHITE) {
            colores[cur_vertex] = GRAY;
            stack.push_back(cur_vertex);
            for(int i : graph[cur_vertex]) {
                if (colores[i] == WHITE) {
                    stack.push_back(i);
                } else if (colores[i] == GRAY){
                    return true;
                }
            }
        } else if(colores[cur_vertex] == GRAY) {
            colores[cur_vertex] = BLACK;
        }
    }
    return false;
}

bool check_country(Graph &country_X) {
    for(int i = 0 ; i < country_X.size() ; ++i) {
        if (dfs_is_cylce(i, country_X)) {
            return true;
        }
    }
    return false;
}

int main() {
    Graph country_X = read_rails();
    bool res = check_country(country_X);
    std::cout << (res ? "NO" : "YES") << std::endl; 
}
