#include <iostream>
#include <vector>

using namespace std;

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
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }

    bool isValid(TreeNode* root, int* max_v, int* min_v) {
        if(root == nullptr) {
            return true;
        }
        if((max_v == nullptr || root->val < *max_v) &&
           (min_v == nullptr || root->val > *min_v) ) {
            return isValid(root->left, &root->val, min_v) &&
                   isValid(root->right, max_v, &root->val);
        } 
        return false;
    }
};


int main() {
    TreeNode *node = new TreeNode(2);
    node->left = new TreeNode(1);
    node->right = new TreeNode(5);
    Solution s;
    std::cout << s.isValidBST(node) << std::endl;
}
