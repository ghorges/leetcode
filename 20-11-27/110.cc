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
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        dfs(root, 0);
        return flag;
    }
    int dfs(TreeNode* root, int deep) {
        if (root == NULL) {
            return 0;
        }

        int t1 = dfs(root->left, deep+1);
        int t2 = dfs(root->right, deep+1);
        if (abs(t1 - t2) > 1) {
            flag = false;
        }
        if (t1 == 0 && t2 == 0) {
            return 1;
        }
        int j = t1 > t2 ? t1 : t2;
        return j + 1;
    }
};
