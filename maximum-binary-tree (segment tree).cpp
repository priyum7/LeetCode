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
    
    
    int buildtree(vector<int>& nums, vector<pair<int,int>>& stree, int l, int r, int treenode)
    {
        if(l==r)
        {
            stree[treenode] = {nums[l], l};
            return l;
        }
        
        int mid = (l+r)/2;
        int a = buildtree(nums, stree, l, mid, 2*treenode);
        int b = buildtree(nums, stree, mid+1, r, (2*treenode)+1);
        
        if(stree[2*treenode].first<stree[(2*treenode)+1].first)
        {
            stree[treenode] = {stree[(2*treenode)+1].first, b};
            return b;
        }
        else
        {
            stree[treenode] = {stree[(2*treenode)].first, a};
            return a;
        }
        
    }
    
    
    pair<int,int> query(vector<pair<int, int>>& stree, int l, int r, int treenode, int start, int end)
    {
        if(l==start && r==end)
        {
            return stree[treenode];
        }
        
        int mid = (l+r)/2;
        
        if(end<=mid)
            return query(stree, l, mid, 2*treenode, start, end);
        else if(start>mid)
            return query(stree, mid+1, r, (2*treenode)+1, start, end);
        else
        {
            pair<int, int> a = query(stree, l, mid, 2*treenode, start, mid);
            pair<int, int> b = query(stree, mid+1, r, (2*treenode)+1, mid+1, end);
            if(a.first > b.first)
            {
                return a;
            }
            else
            {
                return b;
            }
        }
        
    }
    
    
    TreeNode* helper(vector<int>& nums, TreeNode* &root, vector<pair<int, int>>& stree, int l, int r)
    {
        
        if(l>r)
            return NULL;
        
        pair<int, int> max_object = query(stree, 0, nums.size()-1, 1, l ,r);
        
        root = new TreeNode(max_object.first);
        helper(nums, root->left, stree, l, max_object.second-1);
        helper(nums, root->right, stree, max_object.second+1, r);
        
        return root;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        TreeNode* temp;
        int size=nums.size();
        vector<pair<int,int>> stree(4*size);    
        buildtree(nums, stree, 0, size-1, 1);
        
        return helper(nums, temp, stree, 0, nums.size()-1);   
    }
};
