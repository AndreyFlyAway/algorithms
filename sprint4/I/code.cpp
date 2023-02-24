#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

/*
Гоша увлёкся хоккеем и часто смотрит трансляции матчей. Чтобы более-менее разумно оценивать
силы команд, он сравнивает очки, набранные во всех матчах каждой командой.

Гоша попросил вас написать программу, которая по результатам игр двух выбранных команд найдёт
наибольший по длине отрезок матчей, когда эти команды зарабатывали одинаковые очки.

Рассмотрим первый пример:

Результаты первой команды: [1 2 3 2 1].

Результаты второй команды: [3 2 1 5 6].

Наиболее продолжительный общий отрезок этих массивов имеет длину 3 –— это [3 2 1].

Формат ввода
В первой строке находится число n (1 ≤ n ≤ 10000) –— количество матчей, которые были сыграны первой 
командой.

Во второй строке записано n целых чисел –— очки в этих играх.

В третьей строке дано число m (1 ≤ m ≤ 10000) —– количество матчей, которые сыграла вторая команда.

В четвертой строке заданы m целых чисел —– результаты второй команды.

Число очков, заработанных в одной игре, лежит в диапазоне от 0 до 255.

Формат вывода
Выведите целое неотрицательное число —– максимальное количество матчей подряд, в которых команды 
зарабатывали одинаковые очки.


5
1 2 3 2 1
5
3 2 1 5 6

res:
3

5
1 2 3 4 5
3
4 5 9
res:
2
*/

int get_slice_sum(const std::vector<int>& team, int left, int right) {
    if(left == 0) {
        return team[right];
    } else {
        return team[right] - team[left-1];
    }
}

int common_mathes(std::vector<int>& team_1, std::vector<int>& team_2) {
    if (team_2.size() > team_1.size()) {
        std::swap(team_1, team_2);
    }
    for(int i = 1 ; i < team_1.size() ; ++i) {
        team_1[i] += team_1[i-1];
    }
    for(int i = 1 ; i < team_2.size() ; ++i) {
        team_2[i] += team_2[i-1];
    }
    std::cout << "Sums of team 1: ";
    for(int i : team_1) {
        std::cout << i << " ";
    } 
    std::cout << std::endl;
    std::cout << "Sums of team 2: ";
    for(int i : team_2) {
        std::cout << i << " ";
    } 
    std::cout << std::endl;
    int res = 0;
    int slice_border = std::min(team_1.size(), team_2.size()) - 1;
    std::cout << "slice_border "<< slice_border << std::endl;
    std::vector<int> slices_sum_t1;
    std::vector<int> slices_sum_t2;
    while(slice_border != 0) {
        for(int i = 0 ; i < (team_1.size() - slice_border) ; ++i) {
            int cur_sum_t1 = get_slice_sum(team_1, i, slice_border);
            for(int j = 0 ; j < (team_2.size() - slice_border) ; ++j) {
                int cur_sum_t2 = get_slice_sum(team_2, j, slice_border);
                std::cout << "comparing " << cur_sum_t1 << " " << cur_sum_t2 << std::endl;
                if ( cur_sum_t2 == cur_sum_t1) {
                    // res = std::max(res, cur_sum_t2);
                    return slice_border;
                }
            }
        }
        --slice_border;
    }
    return res;
}

int main() {
    int n,v;
    std::vector<int> team_1;
    std::vector<int> team_2;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> v;
        team_1.push_back(v);
    }
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> v;
        team_2.push_back(v);
    }
    std::cout << common_mathes(team_1, team_2) << std::endl;
}
