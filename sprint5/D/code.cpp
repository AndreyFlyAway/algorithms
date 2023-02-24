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

using namespace std;


bool Solution(const Node* root1, const Node* root2) {
  bool ret = false;
  if(root1 != nullptr && root2 != nullptr) {
    if(root1->value == root2->value) {
      ret = Solution(root1->left, root2->left) && Solution(root1->right, root2->right);
    } else {
      ret = false;
    }
  } else if(root1 == nullptr && root2 == nullptr) {
    ret = true;
  } else {
    ret = false;
  }
  return ret;
} 

#ifdef local
void test() {

    Node node1({1, nullptr, nullptr});
    Node node2({2, nullptr, nullptr});
    Node node3({3, &node1, &node2});

    Node node4({1, nullptr, nullptr});
    Node node5({2, nullptr, nullptr});
    Node node6({3, &node4, &node5});
    assert(Solution(&node3, &node6));
}

int main() {
  test();
}
#endif