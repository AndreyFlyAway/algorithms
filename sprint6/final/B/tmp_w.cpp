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
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
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
    std::cout << (res == true ? "NO" : "YES") << std::endl; 
}