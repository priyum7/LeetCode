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
    
    int helper(TreeNode* root, int &result){
        
        if(root==NULL)
            return 0;
        
        
        int left = helper(root->left, result);
        left = max(left,0);
        int right = helper(root->right, result);
        right = max(right,0);
        result = max(result, root->val + left + right);
        
        return root->val+max(left,right);
    }
    
    int maxPathSum(TreeNode* root) {
        
        int result = root->val;
        
        if(root->left == NULL && root->right==NULL)
            return root->val;
        
        helper(root, result);
        
        return result;
        
    }
};