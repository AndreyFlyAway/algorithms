/*
Вы приехали на архипелаг Алгосы (наконец-то!). Здесь есть n достопримечательностей. 
Ваша лодка может высадить вас у одной из них, забрать у какой-то другой, возможно, 
той же самой достопримечательности и увезти на материк.

Чтобы более тщательно спланировать свой маршрут, вы хотите узнать расстояния между 
каждой парой достопримечательностей Алгосов. Некоторые из них соединены мостами, по 
которым вы можете передвигаться в любую сторону. Всего мостов m.

Есть вероятность, что карта архипелага устроена так, что нельзя добраться от какой-то 
одной достопримечательности до другой без использования лодки.

Найдите кратчайшие расстояния между всеми парами достопримечательностей.

Формат ввода
В первой строке даны числа n (1 ≤ n ≤ 100) и m (0 ≤ m ≤ n (n-1)/2). В следующих m 
строках описаны мосты. Каждый мост задаётся номерами двух достопримечательностей 
1 ≤ u, v ≤ n и длиной дороги 1 ≤ L ≤ 103.

Формат вывода
Выведите матрицу n × n кратчайших расстояний. На пересечении i-й строки и j-го столбца 
должно стоять расстояние от i-й до j-й достопримечательности. Если между какой-то парой 
нет пути, то в соответствующей клетке поставьте -1.

Examples:
4 4
1 2 1
2 3 3
3 4 5
1 4 2

res:
0 1 4 2 
1 0 3 3 
4 3 0 5 
2 3 5 0 

3 2
1 2 1
1 2 2

res:
0 1 -1 
1 0 -1 
-1 -1 0 

2 0
res:
0 -1 
-1 0 
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>


class Graph {
public:
    Graph(int v_num, int e_num):
        v_num_(v_num), e_num_(e_num),
        weight_(std::vector<std::vector<int> >(v_num, std::vector<int>(v_num, 0))),
        prev_(std::vector<int>(v_num, -1)),
        visited_(std::vector<bool>(v_num, false)),
        // dist_(std::vector<int>(v_num, std::numeric_limits<int>::infinity()))
        dist_(std::vector<std::vector<int> >(v_num, std::vector<int>(v_num, std::numeric_limits<int>::infinity())))
    {
        std::string in_val;
        for(int i = 0 ; i < v_num ; ++i) {
            weight_[i][i] = 0;
            dist_[i][i] = 0;
        }
        for(int i = 0 ; i < e_num + 1 ; ++i) {
            getline(std::cin, in_val);
            std::vector<int> cur_val = split_string(in_val); 
            if (cur_val.size() == 3) {
                cur_val[0] -= 1;
                cur_val[1] -= 1;
                if (weight_[cur_val[0]][cur_val[1]] == 0 ) {
                    weight_[cur_val[0]][cur_val[1]] = cur_val[2];
                    weight_[cur_val[1]][cur_val[0]] = cur_val[2];
                } else if (cur_val[2] < weight_[cur_val[0]][cur_val[1]] ) {
                    weight_[cur_val[0]][cur_val[1]] = cur_val[2];
                    weight_[cur_val[1]][cur_val[0]] = cur_val[2];
                }
            }
        }
        
    }

void print_res() {
    for(int i = 0 ; i < v_num_ ; ++i) {
        Dijkstra_alg(i);
    }
    for(int i = 0 ; i < dist_.size() ; ++i) {
        for(int j = 0 ; j < dist_[i].size() ; ++j) {
            std::cout << dist_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

private:
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

    void Dijkstra_alg(int start) {
        std::vector<bool> visited(v_num_, false);
        std::vector<int> prev(v_num_, -1);
        std::vector<int> dist(v_num_, std::numeric_limits<int>::max());
        // std::vector<int> dist(weight_[start]);
        dist[start] = 0;

        for(int i = 0 ; i < v_num_ ; ++i) {
            int u = get_min_dist_not_visited_vertex(i, dist, visited);
            visited[u] = true;
            // std::cout << "returned u: " << u << std::endl;
            for(int v = 0 ; v < v_num_ ; ++v) {
                if(!visited[v] && u != v && weight_[u][v] != 0) {
                    relax(u, v, dist);
                }
            }
        }
        for(int &i :  dist) {
            if (i == std::numeric_limits<int>::max() ) {
                i = -1;
            }
        }
        dist_[start] = dist;
    }

    void relax(int in_u, int out_v,
               std::vector<int> &dist) {
        if(dist[in_u] !=std::numeric_limits<int>::max() && dist[out_v] > (dist[in_u] + weight_[in_u][out_v]) ) {
            dist[out_v] = dist[in_u] + weight_[in_u][out_v] ;
        }
    }

    int get_min_dist_not_visited_vertex(int out_v,
                                        std::vector<int> &dist,
                                        std::vector<bool> &visited) {
        int cur_min = std::numeric_limits<int>::max();
        int cur_min_vertex = 0;

        for(int i = 0 ; i < weight_[out_v].size() ; ++i) {
            if ((!visited[i]) && dist[i] < cur_min) {
                cur_min = dist[i];
                cur_min_vertex = i;
            }
        }
        return cur_min_vertex;
    }


private:
    int v_num_;
    int e_num_;
    std::vector<bool> visited_;
    std::vector<std::vector<int> > weight_;
    std::vector<int> prev_;
    std::vector<std::vector<int> > dist_;
};

int main() {
    int v_num = -1, e_num = -1, start = -1;
    std::cin >> v_num >> e_num;
    Graph apologs_ilends(v_num, e_num);
    apologs_ilends.print_res();
}
