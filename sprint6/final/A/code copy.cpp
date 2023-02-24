/*
Examples 1:
4 4
1 2 5
1 3 6
2 4 8
3 4 3

Res:
19

Examples 2:
3 3
1 2 1
1 2 2
2 3 1
Res:
3

Examples 3:
2 0
Res:
Oops! I did it again

Examples 5:
8 10
1 2 5
1 3 6
1 4 13
2 4 8
3 4 3
4 5 7
5 6 12
6 7 13
6 8 15
7 8 14

Res:
75
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
#include <queue>

constexpr std::string_view ERR_MSG = "Oops! I did it again";

// using Pair_int = std::pair<int, int>;
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
        weight_(std::vector<std::vector<int> >(v_num, std::vector<int>(v_num, 0))),
        prev_(std::vector<int>(v_num, -1))
        // edges_(std::priority_queue<EdgeWeigt, std::vector<EdgeWeigt>, customGrerter> ())
    {
        std::string in_val;
        
        // читаю граф, если все узлы связаны
        // if (e_num_ >= v_num) {
            // составляем список не доавбляен узлов для алгоритма MST

            for(int i = 0 ; i < v_num_ ; ++i) {
                not_added_nodes_.insert(i);
            }
            for(int i = 0 ; i < e_num + 1 ; ++i) {
                getline(std::cin, in_val);
                std::vector<int> cur_val = split_string(in_val); 
                if (cur_val.size() == 3) {
                    cur_val[0] -= 1;
                    cur_val[1] -= 1;
                    // std::cout << "read: " << cur_val[0] << " " << cur_val[1] << " " << cur_val[2] << std::endl;
                    if (weight_[cur_val[0]][cur_val[1]] == 0 ) {
                        weight_[cur_val[0]][cur_val[1]] = cur_val[2];
                        weight_[cur_val[1]][cur_val[0]] = cur_val[2];
                    } else if (cur_val[2] > weight_[cur_val[0]][cur_val[1]] ) {
                        weight_[cur_val[0]][cur_val[1]] = cur_val[2];
                        weight_[cur_val[1]][cur_val[0]] = cur_val[2];
                    }
                }
            // }
        }
    }

    void print_res() {
        int res = find_max_MST();
        if (res == -1 ) {
            std::cout << ERR_MSG << std::endl;
        } else {
            std::cout << res << std::endl;
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

    // void add_vertex(int vert) {
    //     added_nodes_.push_back(vert);
    //     not_added_nodes_.erase(vert);
    //     // добавляю ребра 
    //     int max_edge = 0;
    //     Pair_int cur_edge {vert, -1};

    //     for(int i = 0 ; i < weight_[vert].size() ; ++i) {
    //         if(weight_[vert][i] != 0) {
    //             auto it = not_added_nodes_.find(i);
    //             if (it != not_added_nodes_.end()) {
    //                 if(weight_[vert][i] > max_edge) {
    //                     max_edge = weight_[vert][i];
    //                     cur_edge.second = i;
    //                 }
    //             }
    //         }
    //     }
    //     if (cur_edge.second != -1) {
    //         edges_.insert(cur_edge);
    //     }
    // }


    void add_vertex(int vert) {
        added_nodes_.push_back(vert);
        not_added_nodes_.erase(vert);
        // добавляю ребра 
        for(int i = 0 ; i < weight_[vert].size() ; ++i) {
            if(weight_[vert][i] != 0) {
                // edges_.insert(Pair_int {vert, i});
                edges_.push(EdgeWeigt {vert, i, weight_[vert][i]});
            }
        }
    }

    int find_max_MST() {
        int cur_vert = 0;
        add_vertex(0);
        int  max_spanning_tree = 0;

        while ( !not_added_nodes_.empty() && !edges_.empty() )
        {
            // std::set<Pair_int>::iterator it;
            // int max_weight = 0;
            // Pair_int max_weight_pair ;
            // extract max edge
            // for(it = edges_.begin() ; it != edges_.end() ; ++it) {
            //     if(weight_[it->first][it->second] > max_weight) {
            //         max_weight = weight_[it->first][it->second];
            //         max_weight_pair = *it;
            //     }
            // }
            EdgeWeigt max_weight_pair = edges_.top();
            edges_.pop();
            auto it_not_added = not_added_nodes_.find(max_weight_pair.second);
            if(it_not_added != not_added_nodes_.end()) {
                // max_spanning_tree += max_weight;
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
    std::vector<int> prev_;
    std::vector<std::vector<int> > dist_;

    std::vector<int> added_nodes_;
    std::set<int> not_added_nodes_;
    // std::set<Pair_int> edges_;
    std::priority_queue<EdgeWeigt> edges_;
};

void time_test() {
    int v_num = -1, e_num = -1;
    std::cin >> v_num >> e_num;
    MatrixGraph apologs_ilends(v_num, e_num);

    std::cout << "Started" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    apologs_ilends.print_res();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[ms] for " << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms] for " << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[sec] "  << std::endl;

}


int main() {
    // time_test();
    // return 0;
    int v_num = -1, e_num = -1;
    std::cin >> v_num >> e_num;
    MatrixGraph apologs_ilends(v_num, e_num);
    apologs_ilends.print_res();
}