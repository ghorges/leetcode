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
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if (root->val == 0 && root->left == NULL && root->right == NULL) {
            return NULL;
        }
        return root;
    }
    bool dfs(TreeNode* root) {
        if (root == NULL) return false;
        bool t1 = dfs(root->left);
        bool t2 = dfs(root->right);
        if (t1 == false) {
            root->left = NULL;
        }
        if (t2 == false) {
            root->right = NULL;
        }
        if (t1 == false && t2 == false && root->val == 0) {
            return false;
        }
        return true;
    }
};
