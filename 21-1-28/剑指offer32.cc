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
    vector<int> levelOrder(TreeNode* root) {
        if (root == NULL)
        {
            return vector<int>(0);
        }
        list<TreeNode*> que;
        vector<int> rec(0);
        que.push_back(root);
        while(!que.empty()){
            auto p = que.front();
            rec.push_back(p->val);
            if (p->left)
            {
                que.push_back(p->left);
            }
            if (p->right)
            {
                que.push_back(p->right);
            }
            que.pop_front();
        }
        return rec;
    }
};
