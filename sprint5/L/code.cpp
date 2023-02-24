/*
Напишите функцию, совершающую просеивание вниз в куче на максимум. Гарантируется,
что порядок элементов в куче может быть нарушен только элементом, от которого 
запускается просеивание.

Функция принимает в качестве аргументов массив, в котором хранятся элементы кучи,
и индекс элемента, от которого надо сделать просеивание вниз. Функция должна 
вернуть индекс, на котором элемент оказался после просеивания. Также необходимо 
изменить порядок элементов в переданном в функцию массиве. Индексация в массиве,
содержащем кучу, начинается с единицы. Таким образом, сыновья вершины на позиции 
v это 2v и 2v+1. 

Обратите внимание, что нулевой элемент в передаваемом массиве фиктивный, 
вершина кучи соответствует 1-му элементу.
*/
#define local

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#ifndef local
#include "solution.h"
#endif


int siftDown(std::vector<int>& heap, int idx) {
    int in_tree_idx = idx;
    int wrong_idx = idx;
    while (true)
    {
        int c = wrong_idx * 2;
        for(int i = wrong_idx ; (i <= 1) && (c+i) < (heap.size() - 1); ++i) {
            if(heap[in_tree_idx] > heap[c+i]) {
                in_tree_idx = c+i;
            }
        }
        if (in_tree_idx == wrong_idx) {
            break;
        } else {
            std::swap(heap[in_tree_idx], heap[wrong_idx]);
            wrong_idx = in_tree_idx;
        }
    }
    return in_tree_idx;
}

#ifdef local
void test() {
    std::vector<int> sample = {-1, 12, 1, 8, 3, 4, 7};
    int res = siftDown(sample, 2);
    std::cout << res << std::endl;
    assert(res == 5);
}


int main() {
    test();
}
#endif