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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return vector<int>{};
        }
        vector<int> treeOut;
        vector<vector<TreeNode*>> data(0);
        vector<TreeNode*> boo(0);
        boo.push_back(root);
        data.push_back(boo);
        int index = 0;
        while (1) {
            if (data[index].size() == 0) {
                break;
            }
            vector<TreeNode*> far(0);
            TreeNode* end = NULL;
            for (auto &t : data[index]) {
                end = t;
                if (t->left)
                far.push_back(t->left);
                if (t->right)
                far.push_back(t->right);
            }
            data.push_back(far);
            treeOut.push_back(end->val);
            index++;
        }
        return treeOut;
    }
};
