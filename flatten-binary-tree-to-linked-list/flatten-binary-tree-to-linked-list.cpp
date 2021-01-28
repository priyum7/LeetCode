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
    TreeNode* flatten(TreeNode* root) {
        
        if(root==NULL)
        {
            return NULL;
        }
        
        
        TreeNode* left = flatten(root->left);
        
        TreeNode* temp = NULL;
        
        if(left!=NULL)
            temp = left;
        
        while(temp!=NULL && temp->right!=NULL)
        {
            temp = temp->right;
        }
        
        TreeNode* right = flatten(root->right);
        if(right!=NULL)
        {
            if(temp==NULL)
            left=right;
            else
            {
                temp->right = right;
            }
            
        }
        
        root->left = NULL;
        root->right = left;
        return root;
    }
};