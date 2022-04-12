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

bool helper(TreeNode* root, int target)
{
    if(!root)
        return false;
    
    bool left = helper(root->left, target);
    bool right = helper(root->right, target);
    
    if(!left)
        root->left = NULL;
    
    if(!right)
        root->right = NULL;

    if(!left && !right && root->val == target)
        return false;

    return true;
}


class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool res = helper(root, target);
        return res ? root : NULL;
    }
};