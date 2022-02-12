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
    
    void helper(TreeNode* root, vector<int> &result)
    {
        if(!root)
            return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            int temp = q.size();
            for(int t=0;t<temp; t++)
            {
                TreeNode* tempnode = q.front();
                q.pop();
                
                if(t==temp-1)
                    result.push_back(tempnode->val);
             
                if(tempnode->left)
                q.push(tempnode->left);
                if(tempnode->right)
                q.push(tempnode->right);
                
            }
        }
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
       
        map<int, pair<int, int>> mymap;  
        
       vector<int> result;

        
        helper(root, result);
        
        
        return result;
    }
};