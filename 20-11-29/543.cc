// 只用找到最大的就行了，然后相加
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
    int m = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        dfs(root);
        return m;
    }
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int t1, t2;
        t1 = dfs(root->left);
        t2 = dfs(root->right);

        m = max(m, abs(t1 + t2));
        return (t1 > t2) ? (t1 + 1) : (t2 + 1);
    }
};


