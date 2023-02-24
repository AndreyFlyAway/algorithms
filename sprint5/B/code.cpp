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
#include <vector>

using namespace std;


/* Дерево считается сбалансированным, если левое и правое поддеревья
 каждой вершины отличаются по высоте не больше, чем на единицу.*/

// int check_tree(const Node* node, int three_size) {
//   if(node == nullptr) {
//     return three_size;
//   } else {
//     return (check_tree(node->left, three_size+1) - check_tree(node->right, three_size+1));
//   }
// }


// int check_tree_v2(Node* node, int three_size) {
//   const Node* left = nullptr;
//   const Node* rigt = nullptr;
//   const Node* cur_node = nullptr;
//   std::vector<const Node*> nodes_to_check;
//   nodes_to_check.push_back(node);
//   while(!nodes_to_check.empty()) {
//     cur_node = nodes_to_check.back();
//     nodes_to_check.pop_back();
//     if(cur_node->left != nullptr) {
//       nodes_to_check.push_back(cur_node->left);
//     } 
//     if(cur_node->right != nullptr) {
//       nodes_to_check.push_back(cur_node->right);
//     } 
//     if (cur_node->left == nullptr && cur_node->right != nullptr) {
//     } 
//   }
// }

int check_tree(const Node* node, int three_size) {
  int cur_res = -1;
  if(node == nullptr) {
    cur_res = three_size;
  } else {
    int left_res = check_tree(node->left, three_size+1);
    int right_res = check_tree(node->right, three_size+1);
    if (left_res == -1 || right_res == -1) {
      cur_res = -1;
    } else {
      int cur_diff = left_res - right_res;
      if (cur_diff <= 1 && cur_diff >= -1) {
        cur_res = std::max(left_res, right_res);
      } else {
        cur_res = -1;
      }
    }
  }
  return cur_res;
}

bool Solution(const Node* root) {
  // int res = check_tree(root, 0);
  // std::cout << "res: " << res << std::endl;
  return  check_tree(root, 0) != -1;
}

#ifdef local
void test() { 
  {
    Node node_3({7, nullptr, nullptr});
    Node node_2({4, &node_3, nullptr});
    Node node_1({8, nullptr, nullptr});
    Node node0({7, nullptr, nullptr});
    Node node1({1, &node_2, nullptr});
    Node node2({-5, nullptr, &node0});
    Node node3({3, &node1, &node2});
    Node node4({10, nullptr, &node_1});
    Node node5({2, &node3, &node4});
    assert(Solution(&node5));
  }
}

int main() {
  test();
}
#endif