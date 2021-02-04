// 开始想着很麻烦，但是实际上不难，因为这个树本身
// 是对称的，所以只要从根开始，判断左边和右边即可
// 空间复杂度是O（n），因为压栈的原因。
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        trans(root->left, root->right);
        return rec;
    }
    void trans(TreeNode* l, TreeNode* r) {
        if (l == NULL && r==NULL) {
            return;
        }
        if (l == NULL || r == NULL) {
            rec = false;
            return;
        }
        if (l->val != r->val) {
            rec = false;
            return;
        }
        trans(l->left, r->right);
        trans(l->right, r->left);
    }

};
