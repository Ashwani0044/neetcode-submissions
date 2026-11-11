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
    int res = INT_MIN;
    
    int get_max(TreeNode* root) {
        if(!root) return 0;

        int left = get_max(root->left);
        int right = get_max(root->right);

        int path = root->val+max(left, right);
        return max(0, path);
    };

    void dfs(TreeNode* root) {
        if(!root) return;

        int left = get_max(root->left);
        int right = get_max(root->right);

        res = max(res, root->val+left+right);

        dfs(root->left);

        dfs(root->right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};

// can go either left or right
