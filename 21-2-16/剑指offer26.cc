// 题目本身不难，注意审题
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
    int flag = false;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        dfs(A, B);
        return flag;
    }
    void dfs(TreeNode* A, TreeNode* B) {
        if (A == nullptr) return;
        if (A->val == B->val) {
            if (flag == true)
            {
                return;
            }
            flag = true;
            vdfs(A, B);
        }
        dfs(A->left, B);
        dfs(A->right, B);
    }

    void vdfs(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return;
        if (A == nullptr) {
            flag = false;
            return;
        }
        if (A->val != B->val) {
            flag = false;
            return;
        }
        vdfs(A->left, B->left);
        vdfs(A->right, B->right);
    }
};
