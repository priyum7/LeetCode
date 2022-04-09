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

int findHeight(TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }
    
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    
    return max(left, right)+1;
}


string intstr(int i)
{
    string x = "";
    bool neg = false;
    
    if(i == 0)
        return "0";
    
    if(i<0)
    {
        neg = true;
        i = abs(i);
    }
    
    while(i>0)
    {
        x = (char)('0'+(i%10)) + x;
        i= i/10;
    }
    
    return neg ? "-"+x : x;
}

void helper(TreeNode* root, vector<vector<string>> &result, int i, int j, int height)
{
    if(root == NULL)
        return;
        
    result[i][j] = (intstr(root->val));
    
    int col = pow(2, height - i - 1);
    
    helper(root->left, result, i+1, j-col, height);
    helper(root->right, result, i+1, j+col, height);
}


class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        
        int height = findHeight(root)-1;
        vector<vector<string>> result;
        
        int cols = pow(2, height+1)-1;
        
        for(int t=0; t<=height; t++)
        {
            vector<string> temp(cols, ""); 
            result.push_back(temp);
        }
                
        helper(root, result, 0, cols/2, height);
        
        return result;
    }
};