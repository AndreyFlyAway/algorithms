#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>

const char NOT_CHECKED = '-';
const char R_VAL = 'R';
const char B_VAL = 'B';


const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

using Graph = std::vector<std::vector<char>>;
// using Graph = std::vector<std::string>;

// Graph read_rails(int v_num) {
//     std::string str_in;
//     Graph cities(v_num - 1, "");
//     for(int i = 0 ; i < v_num - 1; ++i) {
//         std::cin >> cities[i];
//     }
//     // for(std::string &s : cities) {
//     //     std::cout << s << std::endl;
//     // }
//     return cities;
// }

Graph read_rails() {
    int v_num;
    std::cin >> v_num;
    std::string str_in;
    Graph cities(v_num, std::vector<char> (v_num, '-'));
    for(int i = 0 ; i < v_num-1; ++i) {
        std::cin >> str_in;
        // if(i >= 27) {
        //     std::cout << str_in;
        // }
        for(int j = 0 ; j < str_in.size() ; ++j) {
            cities[i][j+1+i] = str_in[j];
        }
    }
    // printing reslt
    std::cout << "Orig:" << std::endl;
    for(int i = 0 ; i < v_num; ++i) {
        std::cout << i << ": ";
        for(char c: cities[i]) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    return cities;
}


// bool check_all_rails(int start, Graph &cities) {
//     // std::vector<char> visited_cities(cities.size(), NOT_CHECKED);
//     static Graph visited_cities (cities.size(), std::vector<char>(cities.size(), NOT_CHECKED));
//     for(int cur_vertex = start+1 ; cur_vertex < cities.size() ; ++cur_vertex) {
//             for(int i = cur_vertex+1; i < cities[cur_vertex].size() ; ++i) {
//                 if(visited_cities[start][i] == NOT_CHECKED) {
//                     visited_cities[start][i] = cities[cur_vertex][i];
//                 }
//                 if (visited_cities[start][cur_vertex] == cities[cur_vertex][i]) {
//                     if(visited_cities[start][i] != cities[cur_vertex][i])
//                         return false;
//                 } else {
//                     visited_cities[start][i] = cities[cur_vertex][i];
//                 }
//             }
//     }
//     return true;
// }


// bool check_all_rails(int start, Graph &cities) {
//     std::vector<char> colores(cities.size(), NOT_CHECKED);
//     // std::vector<std::vector<char>> colores(cities.size(), std::vector<char>(cities.size(), NOT_CHECKED));
    
//     // filling in color of first element
//     std::deque<int> stack {start};
//     char first_color = cities[0][1];
//     std::cout << "first_color: " << first_color << std::endl;
//     char second_color = NOT_CHECKED;
//     int start_sec = 0;
//     while (!stack.empty())
//     {
//         int cur_vertex = stack.front();
//         stack.pop_front();
//         for(int i = cur_vertex+1; i < cities[cur_vertex].size() ; ++i) {
//             if(cities[cur_vertex][i] == first_color) {
//                 colores[i] = first_color;
//                 stack.push_front(i);
//             } else  {
//                 second_color = cities[cur_vertex][i];
//                 start_sec = cur_vertex;
//             }
//         }
//     }

//     for(int i = 0 ; i < colores.size() ; ++i) {
//         std::cout << "i: " << i << " v: " << colores[i] << std::endl;
//     }
//     // do the same shit but for another color and searching loop
//     std::cout << "second_color: " << second_color << std::endl;

//     stack.clear();
//     stack.push_back(start_sec);
//     while (!stack.empty()) {
//         int cur_vertex = stack.front();
//                 std::cout << "amahere: " << cur_vertex << std::endl;

//         stack.pop_front();
//         for(int i = cur_vertex + 1; i < cities[cur_vertex].size() ; ++i) {
//             if(cities[cur_vertex][i] == second_color) {
//                 if (colores[i] == first_color) {
//                     return false;
//                 }
//                 colores[i] = second_color;
//                 stack.push_front(i);
//             } 
//         }
//     }
//     return true;
// }

// bool check_all_rails(int start, Graph &cities) {
//     std::vector<char> visited_cities(cities.size(), NOT_CHECKED);
//     std::vector<char> finded_path(cities.size(), NOT_CHECKED);
//     std::vector<char> prev(cities.size(), NOT_CHECKED);
//     std::vector<int> colores(cities.size(), NOT_CHECKED);
//     std::deque<int> stack {start};
//      char first_color = cities[0][0];
//     while (!stack.empty())
//     {
//         int cur_vertex = stack.back();
//         stack.pop_back();
//         if(colores[cur_vertex] == WHITE) {
//             colores[cur_vertex] = GRAY;
//             stack.push_back(cur_vertex);
//             // check all chaildes
//             for(int i = cur_vertex+1; i < cities[cur_vertex].size() ; ++i) {
//                 if(cities[cur_vertex][i] == first_color) {
//                     visited_cities[i] = cities[cur_vertex][i];
//                 }
//                 prev[i] = cities[cur_vertex][i];
//                 stack.push_back(i);
//             }
//        } else if(colores[cur_vertex] == GRAY) {
//            colores[cur_vertex] = BLACK;
//        }
//     }
//     for(int i = 0 ; i < visited_cities.size() ; ++i) {
//         std::cout << "i: " << i << " v: " << visited_cities[i] << std::endl;
//     }
//     return true;
// }

// bool check_all_rails(int start, Graph &cities) {
//     std::vector<char> visited_cities(cities.size(), NOT_CHECKED);
//     std::vector<char> finded_path(cities.size(), NOT_CHECKED);
//     std::vector<char> prev(cities.size(), NOT_CHECKED);
//     std::vector<std::vector<char>> graph_colores(cities.size(), std::vector<char>(cities.size(), NOT_CHECKED));
//     std::vector<int> colores(cities.size(), WHITE);
//     std::deque<int> stack {start};
//     char first_color = cities[0][1];
//     char second_color = NOT_CHECKED;
//     int second_color_index = -1;
//     while (!stack.empty())
//     {
//         int cur_vertex = stack.back();
//         stack.pop_back();
//         // if(colores[cur_vertex] == WHITE) {
//         //     colores[cur_vertex] = GRAY;
//             // check all chaildes
//             for(int i = cur_vertex+1; i < cities[cur_vertex].size() ; ++i) {
//                 // if(visited_cities[i] == NOT_CHECKED) {
//                     // visited_cities[i] = cities[cur_vertex][i];
//                     if (cities[cur_vertex][i] == first_color) {
//                         graph_colores[cur_vertex][i] = first_color;
//                         stack.push_back(i);

//                     } else {
//                         if (second_color_index == -1) {
//                             second_color = cities[cur_vertex][i];
//                             second_color_index = i;
//                         }
//                     }
//                 // }
//                 // if (visited_cities[cur_vertex] == cities[cur_vertex][i]) {
//                 //     if(visited_cities[i] == cities[cur_vertex][i] || visited_cities[i] == NOT_CHECKED) {
//                 //         if (cities[cur_vertex][i] == first_color) {
//                 //             graph_colores[cur_vertex][i] = first_color;
//                 //         }
//                 //     }
//                 //         // return false;
//                 // }
//             }
//     //    } else if(colores[cur_vertex] == GRAY) {
//     //        colores[cur_vertex] = BLACK;
//     //    }
//     }

//     // std::cout << "second_color_index " << second_color_index << std::endl;
//     std::cout << "COLORES: " << std::endl;
//     for(int i = 0 ; i < graph_colores.size() ; ++i) {
//         for(int j = 0 ; j <  graph_colores[i].size() ; ++j) {
//             std::cout <<   char(graph_colores[i][j]) << " "; 
//         }
//          std::cout << std::endl;
//     }

//     if (second_color_index != -1) {
//         stack.clear();
//         stack.push_back(0);
//         while (!stack.empty())
//         {
//             int cur_vertex = stack.back();
//             stack.pop_back();
//             // check all chaildes
//             for(int i = cur_vertex+1; i < cities[cur_vertex].size() ; ++i) {
//                 if (cities[cur_vertex][i] == second_color && graph_colores[cur_vertex][i] == first_color) {
//                     return false;
//                 } else {
//                     stack.push_back(i);
//                 }
//             }
//         }
//     }
//     return true;
// }


// static int second_color = -1;
// std::pair<int,int> second_color_index {-1,-1};

// bool check_all_rails(int start, Graph &cities, char cur_color) {
//     // std::cout << "cur_color is " << cur_color << std::endl;
//     static std::vector<int> colores(cities.size(), WHITE);
//     static std::vector<std::vector<char>> graph_colores(cities.size(), std::vector<char> (cities.size(), NOT_CHECKED));
//     std::deque<int> stack;
//     stack.push_back(start);
//     // graph_colores[start][start] = '*';
//     while (!stack.empty())
//     {
//         int cur_vertex = stack.front();
//         stack.pop_front();
//         std::cout << "poped i: " << cur_vertex << std::endl ;
//         if(colores[cur_vertex] == WHITE) {
//             colores[cur_vertex] = GRAY;
//             stack.push_front(cur_vertex);
//             // check all children
//             for(int i = cur_vertex-1; i >= 0; --i) {
//                 if(cities[i][cur_vertex] == cur_color && colores[i] == WHITE){
//                     stack.push_back(i);
//                     graph_colores[i][cur_vertex] = '*';
//                     std::cout << "pushed i: " << i << std::endl;
//                 } else {
//                     // if (second_color == -1) {
//                         second_color_index.first = i;
//                         second_color_index.second = cur_vertex;
//                         second_color = cities[i][cur_vertex];
//                     // }
//                 }
//             }
//         } else if(colores[cur_vertex] == GRAY) {
//            colores[cur_vertex] = BLACK;
//         } 
//     }

//     std::cout << "GRAPH COLORES: " << std::endl;

//     for(int i = 0 ; i < graph_colores.size() ; ++i) {
//         for(int j = 0 ; j < graph_colores[i].size() ; ++j) {
//             std::cout << graph_colores[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
//     std::cout << "Just COLORES: " << std::endl;
//     for(int i = 0 ; i < colores.size() ; ++i) {
//         std::cout << "i: " << i << " " << colores[i] << std::endl;
//     }
//     std::cout <<  "Second color is " << second_color_index.first << " " <<  second_color_index.second << std::endl;
//     // if(second_color_index.first != -1 ) {
//     //     stack.clear();
//     //     stack.push_back(second_color_index);
//     //     while (!stack.empty())
//     //     {
//     //         int cur_vertex = stack.back();
//     //         std::cout << "get " << cur_vertex << std::endl;
//     //         stack.pop_back();
//     //             // check all children
//     //             for(int i = cur_vertex-1; i >= 0; --i) {
//     //                 std::cout << "get " << i << " collor: " << colores[i] << std::endl;
//     //                 if (colores[i] == BLACK) {
//     //                     return false;
//     //                 }
//     //                 if(cities[i][cur_vertex] == second_color){
//     //                     stack.push_back(i);
//     //                 } else {
//     //                     if (second_color == -1) {
//     //                         second_color_index = i;
//     //                         second_color = cities[i][cur_vertex];
//     //                     }
//     //                 }
//     //             }
//     //     }
//     // } else {
//     //     std::cout << "gofuckuoreselfs" << std::endl;
//     // }

//     // for(int i = 0 ; i < colores.size() ; ++i) {
//     //     std::cout << "i: " << i << " " << colores[i] << std::endl;
//     // }
//     return true;
// }
bool simple_dfs(int start, Graph &cities,  std::vector<int> &colores);
bool is_cylce(int start, std::vector<std::vector<int>> &graph);

bool check_all_rails(int start, Graph &cities, char cur_color) {
    // Graph reversed_tree(cities.size(), std::vector<char> (cities.size(), NOT_CHECKED));
    std::vector<std::vector<int>> reversed_tree(cities.size(), std::vector<int>());
    // creating rever tree
    std::vector<int> colores(cities.size(), WHITE);
    char first_color = cities[cities.size()-2][cities.size()-1];
    char second_color = (first_color == R_VAL) ? B_VAL : R_VAL;
    int second_color_pos = -1;
    for(int cur_vertex = cities.size() - 1 ; cur_vertex > 0 ; --cur_vertex) {
        for(int i = 0 ; i != cur_vertex ; ++i) {
            if (cities[i][cur_vertex] == first_color) {
                reversed_tree[cur_vertex].push_back(i);
                // reversed_tree[cur_vertex][i] = first_color;
                // colores[i] = GRAY;
            } else {
                    reversed_tree[cur_vertex].push_back(i);

                // if (second_color_pos == -1) {
                //     second_color_pos = cur_vertex;
                //     reversed_tree[i].push_back(cur_vertex);
                // }
            }
        }
    }

    std::cout << "second_color_pos " << second_color_pos << std::endl;
    // std::cout << "second_color " << second_color << std::endl;
    // std::cout << "first_color " << first_color << std::endl;
    // std::cout << "Reveresed: " << std::endl;

    for(int i = 0 ; i < reversed_tree.size() ; ++i) {
        std::cout << i << " " ;
        for(int j : reversed_tree[i]){
            std::cout << j << " " ;
        }
        std::cout << std::endl;
    }

    return !is_cylce(second_color_pos, reversed_tree);
}

bool is_cylce(int start, std::vector<std::vector<int>> &graph) {
    std::vector<int> colores(graph.size(), WHITE);
    std::vector<int> stack {start};
    while (!stack.empty())
    {
        int cur_vertex = stack.back(); 
        stack.pop_back();
        
        if(colores[cur_vertex] == WHITE) {
            colores[cur_vertex] = GRAY;
            stack.push_back(cur_vertex);
            for(int i = 0; i < graph[cur_vertex].size() ; ++i) {
                if (colores[graph[cur_vertex][i]] == WHITE) {
                    stack.push_back(graph[cur_vertex][i]);
                    // res.push_back(graph[cur_vertex][i]);
                } else if (colores[graph[cur_vertex][i]] == BLACK) {
                    return true;
                }
            }
        } else if(colores[cur_vertex] == GRAY) {
            // res.push_back(cur_vertex);
            colores[cur_vertex] = BLACK;
        } else if(colores[cur_vertex] == BLACK) {
            return true;
        }
    }
    return false;
}

bool simple_dfs(int start, Graph &cities,  std::vector<int> &colores) {
    std::deque<int> stack {start};
    while (!stack.empty())
    {
        int cur_vertex = stack.back();
        stack.pop_back();
        if(colores[cur_vertex] == WHITE) {
            colores[cur_vertex] = GRAY;
            stack.push_back(cur_vertex);
            // check all chaildes
            for(int i = cur_vertex+1; i < cities[cur_vertex].size() ; ++i) {
                if(colores[i] == WHITE) {
                    stack.push_back(i);
                } else if (colores[i] == BLACK) {
                    return false;
                }
            }
       } else if(colores[cur_vertex] == GRAY) {
           colores[cur_vertex] = BLACK;
       } else if(colores[cur_vertex] == BLACK) {
           return false;
       }
    }
    return true;
}


int main() {
    Graph country_X = read_rails();
    bool res;
    // for(int i = 0 ; i < country_X.size() - 1 ; ++i) {
    //     res = check_all_rails(i, country_X);
    //     if (res == false) {
    //         break;
    //     }
    // }
    res = check_all_rails(country_X.size()-1, country_X, country_X[country_X.size()-2][country_X.size()-1]);
    // if (second_color_index != -1) {
    //     res &= check_all_rails(second_color_index, country_X, second_color);
    // }
    std::cout << (res == true ? "YES" : "NO") << std::endl; 
}