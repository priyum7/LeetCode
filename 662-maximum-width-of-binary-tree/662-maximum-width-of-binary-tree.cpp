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
    
    void helper(TreeNode* root, unordered_map<int, pair<unsigned long long,unsigned long long>> &mymap, int row=0, unsigned long long col=0)
    {
        if(!root)
            return;
        
        if(mymap.count(row))
            mymap[row] = make_pair(min(mymap[row].first, col), max(mymap[row].second, col));
        else
            mymap[row] = make_pair(col, col);
        
        helper(root->left, mymap, row+1, 2*col+1);
        helper(root->right, mymap,row+1, 2*col+2);
        
    }
    
    
    int widthOfBinaryTree(TreeNode* root) {
        
        unsigned long long result=0;
        unordered_map<int, pair<unsigned long long,unsigned long long>> mymap;
        helper(root, mymap);
        
        for(int t=0; mymap.count(t); t++)
        {
            result = max(result, mymap[t].second - mymap[t].first + 1);
        }
        
        return result;
        
        
    }
};