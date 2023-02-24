/*
Напишите функцию, которая будет выводить по неубыванию все ключи от 
L до R включительно в заданном бинарном дереве поиска.
Ключи в дереве могут повторяться. Решение должно иметь сложность 
O(h+k), где h –— глубина дерева, k — число элементов в ответе.
В данной задаче если в узле содержится ключ x, то другие ключи, равные x, 
могут быть как в правом, так и в левом поддереве данного узла.
(Дерево строил стажёр, так что ничего страшного).

*/
#define local

#ifdef local
struct Node {  
  int value;  
  const Node* left = nullptr;  
  const Node* right = nullptr;
  Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};  
#endif

#ifndef local
#include "solution.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

/*
Если корень дерева меньше искомого элемента 1500, поиск производится в 
правом поддереве.

Если корень дерева больше или равен искомому элементу 1500, 
мы рекурсивно повторяем процедуру поиска в левой половине.

Если в левой половине элементов не нашлось, значит, корень дерева 
является первым элементом, который имеет стоимость больше либо равную 1500

*/


const Node* find_low(const Node* node, int l)  {
  const Node* ret = nullptr;

  if (node != nullptr) {
    if(node->value < l) {
      ret = find_low(node->right, l);
    } else if(l >= node->value)  {
      ret = find_low(node->left, l);
    }
    ret = find_low(node->right, l);
  }
  return ret;
}

void print_range(const Node* node, int l, int r) {
  Node* ret = find_low(node, l);
  std::cout << ret->value;
}
// void print_range(const Node* node, int l, int r) {
//     if (node == nullptr || node->value > r) {
//        std::cout << std::endl;
//       return;
//     } else {
//       if (node->value >= l) {
//         std::cout << node->value << " ";
//       } 
//     }
//     print_range(node->left, l, r);
//     print_range(node->right, l, r);
// }

#ifdef local
void test() {
    Node node1({nullptr, nullptr, 2});
    Node node2({nullptr, &node1, 1});
    Node node3({nullptr, nullptr, 8});
    Node node4({nullptr, &node3, 8});
    Node node5({&node4, nullptr, 9});
    Node node6({&node5, nullptr, 10});
    Node node7({&node2, &node6, 5});
    print_range(&node7, 2, 8);
    // expected output: 2 5 8 8
}

int main() {
  test();
}
#endif