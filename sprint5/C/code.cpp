// ! Remove define before submitting !
// #define local

/*

Гоша и Алла играют в игру «Удивительные деревья». Помогите ребятам определить, 
является ли дерево, которое им встретилось, деревом-анаграммой?
Дерево называется анаграммой, если оно симметрично относительно своего центра.

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


using namespace std;

bool check_value(const Node* cur_node, int value) {
  bool ret = cur_node == nullptr ? false : cur_node->value == value;
  return ret;
}

bool check_trees(const Node* left, const Node* right) {
  int ret = false;
  if (left != nullptr && right != nullptr) {
    // ret = left->value == right->value;
    if (left->value == right->value) {
      // ret = check_trees(left->left, right->right);
      if (check_trees(left->left, right->right)) {
        ret = check_trees(left->right, right->left);
      }
    }
    // ret = ret && check_trees(left->left, right->right);
    // ret = ret && check_trees(left->right, right->left);
  } else if (left == nullptr && right == nullptr) {
    ret = true;
  } else {
    ret = false;
  }
  return ret;
}

bool Solution(const Node* root) {
  bool ret = true;
  if (root != nullptr) {
    ret = check_trees(root->left, root->right);
  } 
  return ret;
} 

#ifdef local
void test() {
    Node node1({3, nullptr, nullptr});
    Node node2({4, nullptr, nullptr});
    Node node3({4, nullptr, nullptr});
    Node node4({3, nullptr, nullptr});
    Node node5({2, &node1, &node2});
    Node node6({2, &node3, &node4});
    Node node7({1, &node5, &node6});
    assert(Solution(&node7));
}


int main() {
  test();
}
#endif