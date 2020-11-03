// 很简单，把 max 和 min 传入下面的递归中就可以了
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
    int dif = 0;
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        tree(root, root->val, root->val);
        return dif;
    }
    void tree(TreeNode* root, int big, int small) {
        if (root->left) {
            int b1 = max(big, root->left->val);
            int s1 = min(small, root->left->val);
            int t = abs(b1-s1);
            dif = max(dif, t);
            tree(root->left, b1, s1);
        }
        if (root->right) {
            int b1 = max(big, root->right->val);
            int s1 = min(small, root->right->val);
            int t = abs(b1-s1);
            dif = max(dif, t);
            tree(root->right, b1, s1);
        }
        return;
    }
};






