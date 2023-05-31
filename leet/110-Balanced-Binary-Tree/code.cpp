/*
Height-Balanced
A height-balanced binary tree is a binary tree in which the depth of the two 
subtrees of every node never differs by more than one.
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int res = dfs(root, 0);
        return inBalanced;
    }

    int dfs(TreeNode* node, int count) {
        if(node == nullptr) {
            return count;
        }
        int left_v = dfs(node->left, count + 1);
        int right_v = dfs(node->right, count + 1);
        int cur_dif = left_v -right_v;
        if(cur_dif < -1 || cur_dif > 1 ) {
            inBalanced = true;
        }
        return std::max(left_v, right_v);
    }
    
private:
    bool inBalanced = true;
};

int main() {

}