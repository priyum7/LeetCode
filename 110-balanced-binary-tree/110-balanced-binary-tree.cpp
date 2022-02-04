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
    
    int helper(TreeNode* root, bool &result)
    {
        
        if(result == false)
            return 0;
        
        if(root == NULL)
            return 0;
        
        int left = helper(root->left, result);
        int right = helper(root->right, result);
        
        if(abs(left - right)>1)
            result = false;
        
        return max(left, right)+1;

        }
    
    bool isBalanced(TreeNode* root) {
        bool result = true;
        helper(root, result);
        return result;
    }
};