class Solution {
public:
    
    bool helper(int i, int j, vector<vector<int>>& matrix, int target)
    {
        
        
        if(i>=matrix.size() || j>=matrix[0].size())
            return false;
        
        if(matrix[i][j]==target)
            return true;
        
        if( target <= matrix[i][matrix[0].size()-1] && target>=matrix[i][0])
        {
            if(helper(i, j+1, matrix, target))
                return true;
        }
        else
        {
            if(helper(i+1, 0, matrix, target))
                return true;
        }
        return false;
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return helper(0,0,matrix, target);
    }
};