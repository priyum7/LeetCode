class Solution {
public:
    
    
    int helper(vector<vector<int>> &matrix, int m, int n, int  i, int j )
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        
        if(matrix[i][j]!=0)
        {
            return matrix[i][j];
        }
        
        int temp = helper(matrix, m, n, i+1, j)+helper(matrix, m, n, i, j+1);
        
        matrix[i][j] = temp;
        
        return temp;
    }
    
    
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int> > matrix(m,vector<int>(n, 0));
        
        return helper(matrix, m, n, 0, 0);
    }
};