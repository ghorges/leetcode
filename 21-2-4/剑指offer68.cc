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
    TreeNode* rec = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        trans(root, p, q);
        return rec;
    }
    int trans(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return 0;
        int i = trans(root->left, p, q);
        int j = trans(root->right, p, q);
        int sum = i + j;
        if (root == p || root == q) {
            sum += 1;
        }
        if (sum >= 2 && rec == NULL) {
            rec = root;
        }
        return sum;
    }
};
