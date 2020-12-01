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
    
    TreeNode* helper(vector<int>& nums, TreeNode* &root, int l, int r)
    {
        
        if(l>r)
            return NULL;
        
        int max=INT_MIN, index=-1;
        
        for(int a=l;a<=r;a++)
        {
            if(nums[a]>max)
            {    
                max=nums[a];
                index=a;
            }
        }
        
        root = new TreeNode(max);
        helper(nums, root->left, l, index-1);
        helper(nums, root->right, index+1, r);
        
        return root;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        TreeNode* temp;
        return helper(nums, temp, 0, nums.size()-1);
        
    }
};
