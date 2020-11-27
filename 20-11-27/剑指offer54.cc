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
    int kNum = 0;
    int kthLargest(TreeNode* root, int k) {
        if (root == NULL) return 0;
        dfs(root, k);
        return kNum;
    }

    void dfs(TreeNode* root, int& k) {
        if (root->left == NULL && root->right == NULL) {
            k--;
            if (k == 0) {
                kNum = root->val;
            }
            return;
        }
        if (root->right != NULL)
            dfs(root->right, k);
        k--;
        if (k == 0) {
            kNum = root->val;
        }
        if (root->left != NULL)
            dfs(root->left, k);
    }
};
