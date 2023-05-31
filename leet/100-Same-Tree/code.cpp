#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> p_tree;
        std::stack<TreeNode*> q_tree;
        p_tree.push(p), q_tree.push(q);
        while(!p_tree.empty() && !q_tree.empty()) {
            TreeNode* p_cur = p_tree.top();
            TreeNode* q_cur = q_tree.top();
            p_tree.pop(), q_tree.pop();
            if(p_cur != nullptr && q_cur != nullptr) {
                if(p_cur->val != q_cur->val) {
                    return false;
                }
                p_tree.push(p_cur->left);
                p_tree.push(p_cur->right);
                q_tree.push(q_cur->left);
                q_tree.push(q_cur->right);
            } else if(p_cur != q_cur) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    
}