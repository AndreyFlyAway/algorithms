#include <iostream>
#include <vector>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        dfs_order(root, res, 0);
        return res;
    }

    void dfs_order(TreeNode* node, std::vector<std::vector<int>>& res, size_t count) {
        if(node == nullptr) {
            return;
        }
        if(count >= res.size()) {
            res.push_back(std::vector<int> {node->val});
        } else {
            res[count].push_back(node->val);
        }
        dfs_order(node->left, res, count + 1);
        dfs_order(node->right, res, count + 1);
    }
};

int main() {
    Solution s;
}