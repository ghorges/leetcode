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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        trans(root);
        return root;
    }

    void trans(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        swap(root->left, root->right);
        trans(root->left);
        trans(root->right);
    }
};
