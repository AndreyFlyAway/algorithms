/*
Example: Given binary tree

          1
         / \
        2   3
       / \     
      4   5

return: [4, 5, 3], [2], [1].

*/

#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Soltion {
public:
    std::vector<std::vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    } 
private:
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = std::max(dfs(root->left), dfs(root->right)) + 1;
        if (res.size() < level) {
            res.push_back(std::vector<int> {});
        }
        res[level - 1].push_back(root->val);
        return level;
    }

private:
    std::vector<std::vector<int>> res;
};
