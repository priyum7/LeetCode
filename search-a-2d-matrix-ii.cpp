class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        bool flag=false;
        while(true)
        {
            if(matrix[i][j]<target)
            {
                if(i<matrix.size()-1)
                    i++;
                else 
                    break;
            }
            else if(matrix[i][j]>target)
            {
                if(j>0)
                    j--;
                else 
                    break;
            }
            else 
            {
                flag=true;
                break;
            }
        }
        return flag;
    }
};
