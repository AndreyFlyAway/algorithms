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
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
    
    int dfs(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        return std::max(dfs(node->left), dfs(node->right)) + 1;
    }
};

int main() {

}
