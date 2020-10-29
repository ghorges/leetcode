/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 也可以用队列解决，思想是类似的，bfs
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            vector<vector<int>> data1(0);
            return data1;
        }
        vector<vector<TreeNode*>> data(0);
        vector<TreeNode*> first(0);
        first.push_back(root);
        data.push_back(first);

        while(1) {
            vector<TreeNode*> node(0);
            bool flag = true;
            for (auto t : data[data.size()-1]) {
                if (t->left!=NULL) {
                    flag = false;
                    node.push_back(t->left);
                }
                if (t->right!=NULL) {
                    flag = false;
                    node.push_back(t->right);
                }
            }
            if (flag == true) {
                break;
            }
            data.push_back(node);
        }

        vector<vector<int>> data1(0);
        int deep = 0;
        for (int i = 0; i < data.size(); i++) {
            vector<int> node(0);
            if (deep%2==0) {
                for (auto &t : data[i]) {
                    node.push_back(t->val);
                }
            } else {
                for (auto t = data[i].rbegin(); t != data[i].rend(); t++) {
                    node.push_back((*t)->val);
                }
            }
            data1.push_back(node);
            deep++;
        }
        return data1;
    }
};
