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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int height = 0;

        queue<TreeNode*> q;

        q.push(root);
        height++;

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left && temp->right) {
                q.push(temp->left);
                q.push(temp->right);
                height++;
            } else if(temp->left) {
                q.push(temp->left);
                height++;
            } else if(temp->right) {
                q.push(temp->right);
                height++;
            }
        }

        return height;
    }
};
