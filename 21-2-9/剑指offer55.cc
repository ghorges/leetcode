// 不知道是不是理解偏差，这个和我理解的树不一样
// 是我的问题了，注：树中结点的最大层次为树的深度或高度。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rec = true;
    bool isBalanced(TreeNode* root) {
        if (root  == nullptr) {
            return true;
        }
        dfs(root, 0);
        return rec;
    }
    
    int dfs(TreeNode *root, int deep) {
        if (root == nullptr) return deep;
        if (root->left == nullptr && root->right == nullptr) {
            return deep + 1;
        }
        int i = dfs(root->left, deep + 1);
        int j = dfs(root->right, deep + 1);
        if (abs(i - j) > 1) {
            rec = false;
        }
        return max(i, j);
    }
};
