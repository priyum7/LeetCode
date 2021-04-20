class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int t=0;t<matrix.size();t++)
        {
            for(int p=0; p<=t; p++)
            {
                swap(matrix[t][p], matrix[p][t]);
            }
        }
        
        for(int t=0;t<matrix.size();t++)
        {
            int l=0, r=matrix[0].size()-1;
            while(l<r)
            {
                swap(matrix[t][l], matrix[t][r]);
                l++;
                r--;
            }
        }
        
        
        
        
    }
};