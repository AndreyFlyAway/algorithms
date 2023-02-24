/*
В стране X есть n городов, которым присвоены номера от 1 до n. Столица страны
имеет номер n. Между городами проложены железные дороги.

Однако дороги могут быть двух типов по ширине полотна. Любой поезд может ездить 
только по одному типу полотна. Условно один тип дорог помечают как R, а другой 
как B. То есть если маршрут от одного города до другого имеет как дороги типа R, 
так и дороги типа B, то ни один поезд не сможет по этому маршруту проехать. От 
одного города до другого можно проехать только по маршруту, состоящему исключительно 
из дорог типа R или только из дорог типа B.

Но это ещё не всё. По дорогам страны X можно двигаться только от города с меньшим 
номером к городу с большим номером. Это объясняет большой приток жителей в столицу, 
у которой номер n.

Карта железных дорог называется оптимальной, если не существует пары городов A и B 
такой, что от A до B можно добраться как по дорогам типа R, так и по дорогам типа B. 
Иными словами, для любой пары городов верно, что от города с меньшим номером до города 
с бОльшим номером можно добраться по дорогам только какого-то одного типа или же что 
маршрут построить вообще нельзя. Выясните, является ли данная вам карта оптимальной.

Формат ввода
В первой строке дано число n (1 ≤ n ≤ 5000) — количество городов в стране. Далее задана 
карта железных дорог в следующем формате.

Карта задана n-1 строкой. В i-й строке описаны дороги из города i в города i+1, i+2, ..., n. 
В строке записано n - i символов, каждый из которых либо R, либо B. Если j-й символ строки i 
равен «B», то из города i в город i + j идет дорога типа «B». Аналогично для типа «R».

Формат вывода
Выведите «YES», если карта оптимальна, и «NO» в противном случае.

Example 1
In:	
3
RB
R

Out:
NO

Example 2
In:	
4
BBB
RB
B

Out:
YES

Example 3
In:	
5
RRRB
BRR
BR
R
Out:
NO

Example 4
In:	
10
RRBRRBRRR
BBBBBBRB
BBRBRRR
RRBRRR
RBRRR
BBRR
RRR
RR
B
Out:
YES

Example 5
In:
25
BBBRRBBBBBBRBBBBBBBBRBBB
BBRRBBRBRBRRBBBBBRBRBRB
RRRRRRBRBRRRRRRBRRRRRR
RRBRRBRBRRBBBBBRBRBRB
RBBBBBBRBBBBBBBBRBBB
BBBBBBRBBBBBBBBRBBB
RRBRBRRRRBBBRBRRRB
RBRBRRBBBBBRBRBRB
BRBRBBBBBBBBRBRB
RBRRRRRRBRRRRRR
BRBBBBBBBBRBBB
RRRRRRRRRRRRR
BBBBBBBBBBBB
BBBBBRBRBRB
RBBBRBRBRB
BBBRBRBRB
BBRBRRRR
BRBRRRR
RRRRRR
BRBRB
RRRR
BBB
RB
B
Out:
YES
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <random>

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
        for(int j = 0 ; j < str_in.size() ; ++j) {
            cities[i][j+1+i] = str_in[j];
        }
    }
    // printing reslt
    // for(int i = 0 ; i < v_num; ++i) {
    //     std::cout << i << ": ";
    //     for(char c: cities[i]) {
    //         std::cout << c << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return cities;
}


// bool check_all_rails(int start, Graph &cities) {
//     // std::vector<char> visited_cities(cities.size(), NOT_CHECKED);
//     static std::vector<char> visited_cities {cities[start]};
//     for(int cur_vertex = start+1 ; cur_vertex < cities.size() ; ++cur_vertex) {
//             for(int i = cur_vertex+1; i < cities[cur_vertex].size() ; ++i) {
//                 if (visited_cities[cur_vertex] == cities[cur_vertex][i]) {
//                     if(visited_cities[i] != cities[cur_vertex][i])
//                         return false;
//                 }
//             }
//     }
//     return true;
// }

bool check_all_rails(int start, Graph &cities) {
    // std::vector<char> visited_cities(cities.size(), NOT_CHECKED);
    static Graph visited_cities (cities.size(), std::vector<char>(cities.size(), NOT_CHECKED));
    for(int cur_vertex = start+1 ; cur_vertex < cities.size() ; ++cur_vertex) {
            for(int i = cur_vertex+1; i < cities[cur_vertex].size() ; ++i) {
                if(visited_cities[start][i] == NOT_CHECKED) {
                    visited_cities[start][i] = cities[cur_vertex][i];
                }
                if (visited_cities[start][cur_vertex] == cities[cur_vertex][i]) {
                    if(visited_cities[start][i] != cities[cur_vertex][i])
                        return false;
                }
            }
    }
    return true;
}



void time_test() {
    // Graph country_X = {{'R','R','B','B','R','R','B','R','R'},
    //                    {'-','R','R','B','B','B','B','R','R'},
    //                    {'-','-','R','R','B','R','R','R','B'},
    //                    {'-','-','-','R','R','R','R','B','R'},
    //                    {'-','-','-','-','B','B','B','B','B'},
    //                    {'-','-','-','-','-','R','R','B','B'},
    //                    {'-','-','-','-','-','-','B','B','R'},
    //                    {'-','-','-','-','-','-','-','R','B'},
    //                    {'-','-','-','-','-','-','-','-','B'},
    //                    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr('B', 'R'); 
    Graph country_X;
    int N = 2000;
    for(int i = 0 ; i < N ; ++i) {
        // std::string cur_v;
        std::vector<char> cur_v;
        for(int j = 0 ; j < N ; ++j) {
            cur_v.push_back(distr(gen));
        }
        country_X.push_back(cur_v);
    }
    bool res;
    uint test_num = 10000;
    uint ns_total = 0;
    uint ms_total = 0;
    uint ns_cur = 0;
    uint ns_max = 0;
    uint ns_min = std::numeric_limits<uint>::max();

    for(uint i = 0 ; i < test_num ; ++i) {
        std::chrono::steady_clock::time_point begin_cur = std::chrono::steady_clock::now();
        for(int i = 0 ; i < country_X.size() - 1 ; ++i) {
            res = check_all_rails(i, country_X);
            if (res == false) {
                break;
            }
        }
        // res = check_all_rails(0, country_X);
        std::chrono::steady_clock::time_point end_cur = std::chrono::steady_clock::now();
        ns_cur = std::chrono::duration_cast<std::chrono::nanoseconds> (end_cur - begin_cur).count(); 
        ms_total += std::chrono::duration_cast<std::chrono::microseconds> (end_cur - begin_cur).count(); 
        ns_total += ns_cur;
        ns_max = ns_cur > ns_max ? ns_cur : ns_max;
        ns_min = ns_cur < ns_min ? ns_cur : ns_min;
    }
    
    std::cout << "Time difference amount = " << ns_total / test_num << "[ns] for " << test_num << " times" << std::endl;
    std::cout << "Time difference amount = " << ms_total / test_num << "[ms] for " << test_num << " times" << std::endl;
    std::cout << "Time difference MAX = " <<  ns_max << "ns" << std::endl;
    std::cout << "Time difference MIN = " <<  ns_min << "ns" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() / test_num << "[ms] for " << test_num << "times" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms] for " << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[sec] "  << std::endl;

}

int main() {
    time_test();
    return 0;
    Graph country_X = read_rails();
    std::vector<char> visited_cities(country_X.size(), NOT_CHECKED);
    bool res;
    for(int i = 0 ; i < country_X.size() - 1 ; ++i) {
        res = check_all_rails(i, country_X);
        if (res == false) {
            break;
        }
    }
    std::cout << (res == true ? "YES" : "NO") << std::endl; 
}