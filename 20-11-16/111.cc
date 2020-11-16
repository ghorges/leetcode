// 今天划水
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int m = INT_MAX;
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        dfs(root, 1);
        return m;
    }
    void dfs(TreeNode* root, int deep) {
        if (root->left == NULL && root->right == NULL) {
            m = min(deep, m);
            return;
        }
        if (root->left != NULL) {
            dfs(root->left, deep + 1);
        }
        if (root->right != NULL) {
            dfs(root->right, deep + 1);
        }
    }
};
