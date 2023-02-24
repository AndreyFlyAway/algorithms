/** Comment it before submitting 
struct Node {  
  int value;  
  const Node* left = nullptr;  
  const Node* right = nullptr;  
};  
**/

// #include "solution_tree.h"
#include <cmath>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;


struct Node {  
  int value;  
  const Node* left = nullptr;  
  const Node* right = nullptr;  
};  

const int INF = -1e9;

int Solution(const Node* node) {
    static int max_light = 0;
    max_light = std::max(max_light, node->value);
    if(node->left != nullptr) {
        Solution(node->left);
    }
    if(node->right != nullptr) {
        Solution(node->right);
    }
    return max_light;
}

void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({-5, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({2, &node3, nullptr});
    assert(!Solution(&node4) == 3);
}

int main() {
    test();
}