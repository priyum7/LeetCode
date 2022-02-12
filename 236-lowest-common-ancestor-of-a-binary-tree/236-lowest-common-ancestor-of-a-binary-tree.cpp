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
    
    
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &result)
    {
        if(!root)
            return false;
        
        bool left = helper(root->left, p, q, result);
        bool right = helper(root->right, p, q, result);
        
        bool isRoot = false;
        if(root == p || root == q)
            isRoot = true;
        
        if((left && right) || (left&& isRoot) || (right && isRoot))
            result = root;
        
        return left || right || isRoot;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = NULL;
        helper(root, p, q, result);
        return result;
    }
};