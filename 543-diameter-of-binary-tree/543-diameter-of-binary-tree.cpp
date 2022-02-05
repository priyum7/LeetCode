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
    
    int helper(TreeNode* root, int &result) {
        if(root == NULL)
            return 0;
        
        int left = helper(root->left, result);
        int right = helper(root->right, result);
        
        if(result<left+right)
            result = left+right;
        
        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int result=INT_MIN;
        helper(root, result);
        return result;
    }
};