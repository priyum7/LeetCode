class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size(), 0));
        
        for(int t=0;t<matrix.size();t++)
        {
            for(int q=0;q<matrix[0].size();q++)
            {
                result[q][t] = matrix[t][q];
            }
        }
        return result;
    }
};