/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 只需要看这个节点大小就行
class Solution {
public:
    vector<TreeNode*> pRoot;
    vector<TreeNode*> qRoot;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) 
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) 
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

/*
// 没看到二叉搜索树而写的...
class Solution {
public:
    vector<TreeNode*> pRoot;
    vector<TreeNode*> qRoot;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        vector<TreeNode*> t;
        dfs(root, p, q, t);
        int i = 0, j = 0;
        for (; i < pRoot.size() && j < qRoot.size(); i++, j++) {
            if (pRoot[i] != qRoot[j]) {
                break;
            }
        }
        return pRoot[i - 1];
    }
    void dfs(TreeNode* root, TreeNode *p, TreeNode *q, vector<TreeNode*> t) {
        if (root == NULL) {
            return;
        }
        t.push_back(root);
        if (root == p) {
            pRoot = t;
        }
        if (root == q) {
            qRoot = t;
        }
        dfs(root->left, p, q, t);
        dfs(root->right, p, q, t);
    }
};
*/
