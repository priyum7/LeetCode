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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        if(root)
            q.push(root);
        else
            return {};
        
        vector<vector<int>> result;
        result.push_back({root->val});
        
        int counter = 0;
        
        while(q.size())
        {
            int temp_size = q.size();
            vector<int> temp_result;
            for(int t=0; t<temp_size; t++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                    temp_result.push_back(temp->left->val);    
                }
                
                if(temp->right){
                    q.push(temp->right);
                    temp_result.push_back(temp->right->val);
                }
                
            }
            
            if(counter%2==0)
                reverse(temp_result.begin(), temp_result.end());
            
            if(temp_result.size())
            result.push_back(temp_result);
            
            counter++;
        }
        return result;
    }
};