class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_map<int,int> row;
        unordered_map<int,int> column;
        
        for(int i=0;i<matrix.size();i++)
        {
           for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]++;
                    column[j]++;
                }
            } 
        }
        
        for(int i=0;i<matrix.size();i++)
        {
           for(int j=0;j<matrix[0].size();j++)
            {
                if(row.count(i)>0 || column.count(j)>0)
                {
                    matrix[i][j]=0;
                }
            } 
        }
        
    }
};