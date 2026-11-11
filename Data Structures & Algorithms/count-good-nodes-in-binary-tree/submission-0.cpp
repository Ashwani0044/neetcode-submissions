/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* root, int maxi) {
        if(!root) return 0;

        int res = (root->val >= maxi)?1:0;

        maxi = max(maxi, root->val);

        res += dfs(root->left, maxi);
        res += dfs(root->right, maxi);

        return res;
    } 
};
