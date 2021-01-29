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
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int leftin, int rightin, int leftpre, int rightpre,  unordered_map<int,int>& prehash,  unordered_map<int,int>& inhash)
    {
        if(rightin<leftin)
        {
            return NULL;
        }
            
        if(leftin == rightin)
        {
            TreeNode* temp = new TreeNode(inorder[leftin]);
            return temp;
        }
        
        int root=preorder[leftpre];
        
        TreeNode* node = new TreeNode(root);
        
        if(inorder[leftin] != preorder[leftpre])
        {
            node->left = helper(preorder, inorder, leftin, inhash[root]-1, leftpre+1, leftpre+1 + (inhash[root]-1 - leftin) , prehash, inhash);
        }
        
        if(rightin-inhash[root]>0)
        {
            node->right = helper(preorder, inorder, inhash[root]+1, rightin, leftpre+1 + (inhash[root]-1 - leftin)+1, rightpre , prehash, inhash);
        }
        
        
       return node; 
        
        
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     
        unordered_map<int,int> prehash;
        unordered_map<int,int> inhash;
        
        for(int t=0;t<preorder.size();t++)
        {
            prehash[preorder[t]] = t;
        }
        
        for(int t=0;t<inorder.size();t++)
        {
            inhash[inorder[t]] = t;
        }
        
        
        
        return helper(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1, prehash, inhash);
    }
};