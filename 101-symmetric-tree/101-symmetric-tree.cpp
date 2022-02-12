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
    bool isSymmetric(TreeNode* root) {
        
        if(!root)
            true;
        
        list<TreeNode*> q;
        q.push_back(root);
        
        while(q.size())
        {
            int temp = q.size();
            list<TreeNode*>::iterator l=q.begin(), r=q.end();
            r--;
            for(; l!=r; l++, r--)
            {
                if((*l)->val!=(*r)->val)
                    return false;
            }
            
            for(int t=0;t<temp; t++)
            {
                TreeNode* tempnode = q.front();
                q.pop_front();
             
                if(tempnode->val != INT_MIN)
                {
                    if(tempnode->left)
                    q.push_back(tempnode->left);
                    else
                    q.push_back(new TreeNode(INT_MIN));
                    
                    if(tempnode->right)
                    q.push_back(tempnode->right);
                    else
                    q.push_back(new TreeNode(INT_MIN));
                }
            }
        }
        
        return true;
    }
};