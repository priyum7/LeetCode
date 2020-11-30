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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL)
            return {};
        
        queue<TreeNode*> nodelist;
        nodelist.push(root);
        vector<vector<int>> result;
        
        while(nodelist.size()!=0)
        {   
            int size = nodelist.size();
            vector<int> temp;
            
            while(size>0)
            {
                TreeNode *currnode = nodelist.front();
                nodelist.pop();
                temp.push_back(currnode->val);
                
                if(currnode->left!=NULL)
                    nodelist.push(currnode->left);
                if(currnode->right!=NULL)
                    nodelist.push(currnode->right);
                
                size--;
            }
            
            result.push_back(temp);
        }
        
        return result;
        
    }
};
