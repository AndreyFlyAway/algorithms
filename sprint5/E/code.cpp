/*
Гоша понял, что такое дерево поиска, и захотел написать функцию, которая определяет, 
является ли заданное дерево деревом поиска. Значения в левом поддереве должны быть 
строго меньше, в правом —- строго больше значения в узле.
Помогите Гоше с реализацией этого алгоритма.

3
0 2 1 2
1 5 None None
2 3 None None
*/

// ! Remove define before submitting !
// #define local

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
#include <unordered_set>
#include <limits>

using namespace std;

const bool LEFT_DIRECT = true;
const bool RIGHT_DIRECT = false;

bool check_tree(const Node* node, int root_value, bool direction) {
  if(node == nullptr) {
    return true;
  } else {
    if (direction == LEFT_DIRECT && node->value >= root_value) {
      return false;
    } else if(direction == RIGHT_DIRECT && node->value <= root_value) {
      return false;
    }
    if ( node->left != nullptr && node->left->value > node->value ) {
      return false;
    }
    if ( node->right != nullptr && node->right->value < node->value ) {
      return false;
    }
    return (check_tree(node->left, root_value, direction) &&
            check_tree(node->right, node->value, direction));
  }
}

/*
функция print_reversed(vertex)
  для каждого ребёнка child из vertex.children
    print_reversed(child)
  print(vertex.value) 
*/

void check_tree_arr(const Node* node, bool& res) {
  static int last_val = 0;
  if (node == nullptr) {
    return;
  } 
  check_tree_arr(node->left, res);
  // std::cout << node->value << " ";
  if (last_val >= node->value) {
    res = false;
    return;
  }
  // if (direction == RIGHT_DIRECT && last_val > node->value) {
  //   // res = false;
  //   return false;
  // }
  last_val = node->value;
  check_tree_arr(node->right, res);
}

bool Solution(const Node* root) {
  bool res = true;
  check_tree_arr(root, res);
  return res;
} 

#ifdef local
void test() {
    {
      Node node1({1, nullptr, nullptr});
      // Node false_node({7, nullptr, nullptr});
      // Node node2({4, nullptr, &false_node});
      Node node2({4, nullptr, nullptr});
      Node node3({3, &node1, &node2});
      Node node4({7, nullptr, nullptr});
      Node node5({6, nullptr, &node4});
      Node node6({10, nullptr, nullptr});
      Node node7({9, &node5, &node6});
      Node node8({5, &node3, &node7});
      assert(Solution(&node8));
    }
    {
      Node node1({1, nullptr, nullptr});
      Node node2({5, nullptr, nullptr});
      Node node3({3, &node1, &node2});
      Node node4({8, nullptr, nullptr});
      Node node5({5, &node3, &node4});
      assert(!Solution(&node5));
    }
    {
      Node node1({4, nullptr, nullptr});
      Node node2({5, nullptr, nullptr});
      Node node3({3, &node1, nullptr});
      Node node4({8, &node2, nullptr});
      Node node5({5, &node3, &node4});
      assert(!Solution(&node5));
    }
    {
      /*
      7
      0 5 1 2
      1 3 3 4
      2 8 5 6
      3 1 None None
      4 3 None None
      5 6 None None
      6 9 None None
      */
      Node node6({9, nullptr, nullptr});
      Node node5({6, nullptr, nullptr});
      Node node4({3, nullptr, nullptr});
      Node node3({1, nullptr, nullptr});
      Node node2({8, &node5, &node6});
      Node node1({3, &node3, &node4});
      Node node0({5, &node1, &node2});
      assert(!Solution(&node0));
    }
}

int main() {
  test();
}

#endif