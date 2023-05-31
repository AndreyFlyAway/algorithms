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
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* cur_node) {
        if(cur_node == nullptr) {
            return 0;
        }
        int left_v = dfs(cur_node->left);
        int right_v = dfs(cur_node->right);
        res = std::max(res, left_v + right_v);
        return std::max(left_v, right_v) + 1;
    }

    int res = 0;
};

int main() {

}