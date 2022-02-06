#include <unordered_map>
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

class element{
    public:
    int value;
    int roworder;
    
    element(int x, int y)
    {
        this->value = x;
        this->roworder = y;
    }
};

    
struct comparison{
    bool operator()(element &e1, element &e2){
        if(e1.roworder<e2.roworder)
            return false;
        else if(e1.roworder == e2.roworder){
            if(e1.value < e2.value)
                return false;
        }
        return true;
    }
};


class Solution {
public:
    
    pair<int, int> helper(TreeNode* root, unordered_map<int, priority_queue<element, vector<element>, comparison>> &result, int col=0, int row=0)     
    {
        if(root == NULL)
            return make_pair(INT_MAX, INT_MIN);
        
        priority_queue<element, vector<element>, comparison> &colresult = result[col];
        
        colresult.push(element(root->val, row));
        
        pair<int, int> left = helper(root->left, result, col-1, row+1);
        pair<int, int> right = helper(root->right, result, col+1, row+1);
        
        return make_pair(min(col, min(left.first, right.first)), max(col, max(left.second, right.second)));
        
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        unordered_map<int, priority_queue<element, vector<element>, comparison>> result;
        pair<int, int> cols = helper(root, result);
        
        vector<vector<int>> result_format;
        
        for(int t=cols.first;t<=cols.second;t++)
        {
            if(result.count(t))
            {
                priority_queue<element, vector<element>, comparison> temp = result[t];
                vector<int> temp_result;
                while(temp.size())
                {
                    temp_result.push_back(temp.top().value);
                    temp.pop();
                }
                result_format.push_back(temp_result);
            }
        }
        
        return result_format;
    }
};