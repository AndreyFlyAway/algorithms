// ! Remove define before submitting !
// #define local

/*

Алла хочет побывать на разных островах архипелага Алгосы. Она составила карту.
Карта представлена в виде дерева: корень обозначает центр архипелага, узлы –— 
другие острова. А листья —– это дальние острова, на которые Алла хочет попасть.
Помогите Алле определить максимальное число островов, через которые ей нужно 
пройти для совершения одной поездки от стартового острова до места назначения, 
включая начальный и конечный пункты.

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

int deepness(const Node* cur_node, int count) {
  int ret = count;
  if (cur_node != nullptr) {
    int left_count = deepness(cur_node->left, count+1);
    int right_count = deepness(cur_node->right, count+1);
    ret = std::max(left_count, right_count);
  } 
  
  return ret;
}

int Solution(const Node* root) {
  return deepness(root, 0);
} 

#ifdef local
void test() {
    Node node0({0, nullptr, nullptr});
    Node node1({1, &node0, nullptr});
    Node node2({4, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({8, nullptr, nullptr});
    Node node5({5, &node3, &node4});
    assert(Solution(&node5) == 4);
}


int main() {
  test();
}
#endif