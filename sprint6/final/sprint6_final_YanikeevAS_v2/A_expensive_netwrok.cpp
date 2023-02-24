/* номер посылки: 80478830*/
/*
Принцип работы:
Составляеться остановное дерево на основе максимальныых наибольших путей. Алгоритм
работает на основе приоритетной очереди, в приоритетную очередь помещаются ребра,
которае будут осматривать на предмет наибольшего пути (наибольшего веса), для этого 
заведенна структура EdgeWeigt, которая содержит какой вес имеет путь из одного узла 
в другой. Для этой структуры определена операция меньше.

Описание класса MatrixGraph:
Конструктор - получает на вход колиество ребер и количество узлов, считвыает граф.
print_res - вывод результата или сообщения об ошибке.
split_string - разделение считанной строки с данными по пробелам, помещает резултат
в вектор.
add_vertex - добавление узла в остов. Помешает узел в список на рассмотренных, 
удаляет из списка нерассмотренных, для теккущеего узла береться ребро с максимальным
весом и помещается в очередь с приоритетом. 
find_max_MST - поиска максимального остова.


Порядок дейсвтий:
1. Чтение графа в конструкторе графа MatrixGraph. В вектор с непосещенных вершин, 
помещаю все считанные вершины.
2. Поиск максимального оставного дерева в методе find_max_MST:
  2.1. Для поиска оставного дерева не важна точка отсчета, добавляю в качестве 
  точки отсчета нулевой узел. 
  2.2. Пока вектор с непосещщеными вершинами и очередь в ребрами не пуста выполняется:
    2.2.1. Из очереди берется ребро с максиамльной длинной.
    2.2.2. У узла ищеться индеке узла в который ведет ребро.
    2.2.3. Если индексузла узла из 2.2.2 найден, береться знанчение веса ребра, добавляется к результату.
    Индекс перемещается из списка нерассмотренных в список рассмотреных. 
    Для рассматриваемого узла берееться ребро с максимальной длинной, помещается в 
    очередь с приоретом.
    2.2.3. Если рассмотрелись все узлы - выводится резултат, иначе выводится ошибка.
3. Вывод результата или сообщения об ошибке.

Временная сложность:
O(e*log(v)), где e - количество рёбер в графе, а v - количество вершин.

Пространственна сложность:
O(e) для очереди с приоритетом, O(e*v) для хранения графа, где e - количество вершин, 
v - количество рёбер.

Доказательство коррекности:
Граф неориентированный, значит можно начинать с любой точки, т.к. смежные вершины началной 
точки все равно будут рассмотрены. Приоритетная очередь позволит брать максимальные пути 
для остова.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>

constexpr std::string_view ERROR_MSG = "Oops! I did it again";

struct EdgeWeigt{
    int first;
    int second;
    int weight;

    friend bool operator< (EdgeWeigt const& lhs, EdgeWeigt const& rhs) {
        return lhs.weight < rhs.weight;
    }
};

class MatrixGraph {
public:
    MatrixGraph(int v_num, int e_num):
        v_num_(v_num), e_num_(e_num),
        weight_(std::vector<std::vector<int> >(v_num, std::vector<int>(v_num, 0)))
    {
        std::string in_val;
        
            for(int i = 0 ; i < v_num_ ; ++i) {
                not_added_nodes_.insert(i);
            }
            for(int i = 0 ; i < e_num + 1 ; ++i) {
                getline(std::cin, in_val);
                std::vector<int> cur_val = split_string(in_val); 
                if (cur_val.size() == 3) {
                    /* уменьшаю на 1, т.к. индекс на вход подаются с 1 до N, а храняться в 
                    массиве индексами с 0 до n */
                    cur_val[0] -= 1;
                    cur_val[1] -= 1;
                    if (weight_[cur_val[0]][cur_val[1]] == 0 ) {
                        weight_[cur_val[0]][cur_val[1]] = cur_val[2];
                        weight_[cur_val[1]][cur_val[0]] = cur_val[2];
                    } else if (cur_val[2] > weight_[cur_val[0]][cur_val[1]] ) {
                        weight_[cur_val[0]][cur_val[1]] = cur_val[2];
                        weight_[cur_val[1]][cur_val[0]] = cur_val[2];
                    }
                }
        }
    }

    void print_res() {
        int res = find_max_MST();
        if (res == -1 ) {
            std::cout << ERROR_MSG << std::endl;
        } else {
            std::cout << res << std::endl;
        }
    }

private:
    static std::vector<int> split_string(const std::string &expr_in) {
        std::vector<int> res;
        std::istringstream iss(expr_in);
        std::string item;
        while (getline(iss, item, ' ')) {
            res.push_back(std::stoi(item));
        }
        return res;
    }

    void add_vertex(int vert) {
        added_nodes_.push_back(vert);
        not_added_nodes_.erase(vert);
        for(int i = 0 ; i < weight_[vert].size() ; ++i) {
            if(weight_[vert][i] != 0) {
                edges_.push(EdgeWeigt {vert, i, weight_[vert][i]});
            }
        }
    }

    int find_max_MST() {
        add_vertex(0);
        int  max_spanning_tree = 0;

        while ( !not_added_nodes_.empty() && !edges_.empty() )
        {
            EdgeWeigt max_weight_pair = edges_.top();
            edges_.pop();
            auto it_not_added = not_added_nodes_.find(max_weight_pair.second);
            if(it_not_added != not_added_nodes_.end()) {
                max_spanning_tree += max_weight_pair.weight;
                add_vertex(max_weight_pair.second);
            }
        }

        if(!not_added_nodes_.empty()) {
            return -1;
        } else {
            return max_spanning_tree;
        }
    }

private:
    int v_num_;
    int e_num_;
    std::vector<std::vector<int> > weight_;
    std::vector<int> added_nodes_;
    std::set<int> not_added_nodes_;
    std::priority_queue<EdgeWeigt> edges_;
};

int main() {
    int v_num = -1, e_num = -1;
    std::cin >> v_num >> e_num;
    MatrixGraph apologs_ilends(v_num, e_num);
    apologs_ilends.print_res();
}
