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
    
    pair<int,int> helper(TreeNode* root)
    {
        if(root == NULL)
            return make_pair(0,0);
        
         pair<int, int> a = helper(root->left);
         pair<int, int> b = helper(root->right);
        
        int child_max_diameter = max(a.first, b.first);
        int child_max_height = max(a.second, b.second);
        
        return make_pair(max(a.second+b.second+1,child_max_diameter), child_max_height+1);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        return helper(root).first-1;
        
    }
};
