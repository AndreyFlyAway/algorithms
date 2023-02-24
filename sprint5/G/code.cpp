// ! Remove define before submitting !
#define local

/*
Тимофей устраивает соревнования по спортивному ориентированию в своём офисе.
Схема офиса представлена в виде дерева. Посещая каждый пункт, можно зарабатывать 
или терять очки. Если в узле записано положительное число, это значение 
добавляется к текущему количеству очков участника. Если отрицательное —– очки 
вычитаются. Если 0 –— их количество не меняется. Нужно определить, какое максимальное 
число очков можно заработать, пройдя по пути из какого-то пункта A в какой-то (возможно, тот же)
пункт B.

Путь не обязательно должен проходить через корень или содержать лист. Путь должен 
содержать по крайней мере один узел.

Пример 1:
В дереве всего три вершины, во всех вершинах записаны положительные числа, 
поэтому объединим все три вершины в один путь. В ответе получим: 
1 + 1 + 2 = 4.

Пример 2:
Теперь в дереве есть вершина с отрицательным весом, через неё в данном случае 
проходить будет невыгодно. Оптимальный путь: 
2 + 7 + 3 = 12.

Пример 3:
Оптимальный путь: 
7+ 2 + 3 + 9 = 21.

Пример 4:
В этот раз имеет смысл пройти через вершину с отрицательным весом, так как в левом 
поддереве вершины − 3 лежит 5. 
Оптимальный путь: 
2 + 2 − 3 + 5 = 6.
*/

#ifdef local
struct Node {  
  int value;  
  const Node* left = nullptr;  
  const Node* right = nullptr;
  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};  
#endif

#ifndef local
#include "solution_tree.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int find_max_path(const Node* node, int last_val) {
  if (node == nullptr) {
    return last_val;
  }
  int res_1 = find_max_path(node->left, last_val + node->value);
  int res_2 = find_max_path(node->right, last_val + node->value);
  return std::max(std::max(res_1, res_2), last_val);
}

int Solution(const Node* root) {
    return find_max_path(root, 0);
}

#ifdef local
void test() {
    Node node1({5, nullptr, nullptr});
    Node node2({1, nullptr, nullptr});
    Node node3({-3, &node2, &node1});
    Node node4({2, nullptr, nullptr});
    Node node5({2, &node4, &node3});
    int res = Solution(&node5);
    std::cout << res << std::endl;
    assert(res == 6);
}

int main() {
  test();
}
#endif