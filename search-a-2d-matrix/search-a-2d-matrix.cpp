class Solution {
public:
    
    bool helper(vector<vector<int>>& matrix, int target, int left, int right)
    {
        if(left>right)
        {
            return false;
        }
        
        else if(left<=right)
        {
            int mid = (left+right)/2;
            int curr = matrix[mid/matrix[0].size()][mid%matrix[0].size()];
            
            if(curr==target)
            {
                return true;
            }
            else if(target<curr)
            {
                if(helper(matrix, target, left, mid-1))
                    return true;
            }
            else
            {
                 if(helper(matrix, target, mid+1, right))
                     return true;
            }
            
           
            
        
        }
         return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0)
            return false;
        else if(matrix[0][0]==target)
            return true;
        else
        
        return helper(matrix, target, 0, (matrix.size()*matrix[0].size())-1);
        
    }
};