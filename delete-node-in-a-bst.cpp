/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL;
        
        if(root->val == key)
        {
            if(root->left==NULL && root->right==NULL)
                return NULL;
            
            else if(root->left!=NULL && root->right==NULL)
                return root->left;
            
            else if(root->right!=NULL && root->left==NULL)
                return root->right;
            
            else
            {
                TreeNode* temp = root->right;
                    while(temp->left!=NULL)
                    {
                        temp=temp->left;
                    }
                int tempdata = temp->val;
                    root->right = deleteNode(root->right, tempdata);
                    root->val=tempdata;                
                return root;
            }
            
        }
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        
        return root;
    }
};
