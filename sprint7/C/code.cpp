/*
Гуляя по одному из островов Алгосского архипелага, Гоша набрёл на пещеру, в 
которой лежат кучи золотого песка. К счастью, у Гоши есть с собой рюкзак 
грузоподъёмностью до M килограмм, поэтому он может унести с собой какое-то 
ограниченное количество золота.

Всего золотых куч n штук, и все они разные. В куче под номером i содержится 
mi килограммов золотого песка, а стоимость одного килограмма — ci алгосских 
франков.

Помогите Гоше наполнить рюкзак так, чтобы общая стоимость золотого песка в 
пересчёте на алгосские франки была максимальной.

Формат ввода
В первой строке задано целое число M — грузоподъёмность рюкзака Гоши (0 ≤ M ≤ 108).

Во второй строке дано количество куч с золотым песком — целое число n (1 ≤ n ≤ 105).

В каждой из следующих n строк описаны кучи: i-ая куча задаётся двумя целыми 
числами ci и mi, записанными через пробел (1 ≤ ci ≤ 107, 1 ≤ mi ≤ 108).

Формат вывода
Выведите единственное число —– максимальную сумму (в алгосских франках), 
которую Гоша сможет вынести из пещеры в своём рюкзаке.

Examples:
In:
10
3
8 1
2 10
4 5
Out:
36

In:
10000
1
4 20
Out:
80

*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

struct GoldHeap
{
    unsigned long long cost;
    unsigned long long mass_kg;
};


unsigned long long comp(GoldHeap &f, GoldHeap &s) {
    if(f.cost > s.cost) {
        return true;
    } else if(f.cost == s.cost && f.mass_kg > s.mass_kg) {
        return true;
    }
    return false;
}

unsigned long long count_max_cost(unsigned long long backpack_size, std::vector<GoldHeap> &heaps) {
    unsigned long long total_cost = 0;
    unsigned long long last_space = backpack_size;
    std::sort(heaps.begin(), heaps.end(), comp);

    // std::cout << "Sorted" << std::endl;
    // for(auto &p : heaps) {
    //     std::cout << p.mass_kg << " " << p.cost << std::endl; 
    // }

    for(unsigned long long i = 0 ; i < heaps.size() && last_space > 0 ; ++i)
    {
        if (last_space < heaps[i].mass_kg) {
            total_cost += last_space * heaps[i].cost;
            last_space = 0;
        } else {
            total_cost += heaps[i].mass_kg * heaps[i].cost;
            last_space -= heaps[i].mass_kg;
        }
    }
    
    return total_cost;
}


int main() {
    unsigned long long backpack_size;
    unsigned long long heaps_num;
    std::cin >> backpack_size;
    std::cin >> heaps_num;
    std::vector<GoldHeap> heaps(heaps_num);
    for(GoldHeap &h: heaps) {
        std::cin >> h.cost; // ci
        std::cin >> h.mass_kg; //mi
    }
    std::cout <<  count_max_cost(backpack_size, heaps) << std::endl;
}