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
    
    int helper(TreeNode* root, int* maxsum, unordered_map<int,int> &hash)
    {
        if(root==NULL)
            return 0;
        
        int left = helper(root->left, maxsum, hash);
        int right = helper(root->right, maxsum, hash);
        
        int sum = root->val+left+right;
        hash[sum]++;
        
        *maxsum = max(*maxsum, hash[sum]);
        return sum;
        
        
    }
    
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        unordered_map<int,int> hash;
        int max = INT_MIN;
        helper(root, &max, hash);
        vector<int> result;
        
        for(auto i:hash)
        {
            if(i.second== max)
            {
                result.push_back(i.first);
            }
        }
        cout<<max;
        
        return result;
    }
};