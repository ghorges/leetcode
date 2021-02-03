// 之前写的太绕了，改进新版的
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
    struct pairs {
        bool p;
        bool q;
    };
    pairs trans(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return pairs{};
        pairs i = trans(root->left, p, q);
        pairs j = trans(root->right, p, q);
        pairs r;
        r.p = i.p || j.p;
        r.q = i.q || j.q;

        if (root == p) {
            r.p = true;
        }
        if (root == q) {
            r.q = true;
        }
        if (rec == NULL && r.p == true && r.q == true) {
            rec = root;
        }
        return r;
    }
};
