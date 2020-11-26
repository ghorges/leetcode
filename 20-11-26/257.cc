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
    vector<string> rec;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return rec;
        }
        string str = "";
        dfs(root, str);
        return rec;
    }
    void dfs(TreeNode* root, string s) {
        s += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            rec.push_back(s);
            return;
        }
        s += "->";
        if (root->left != NULL) {
            dfs(root->left, s);
        }
        if (root->right != NULL) {
            dfs(root->right, s);
        }
    }
};
