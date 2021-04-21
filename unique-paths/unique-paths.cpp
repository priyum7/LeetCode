class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int arr[m][n];
        
        
        if(m==1 || n==1)
            return 1;
        
        for(int t=0; t<m; t++)
        {
            arr[t][n-1] = 1;
        }
        
        for(int t=0; t<n; t++)
        {
            arr[m-1][t] = 1;
        }
        
        int row = m-2, column=n-2;
        
        while(true)
        {
            
            int tempRow = row, tempColumn = column;
            
            
            if(row==0 && column==0)
            {
                arr[0][0] = arr[1][0] + arr[0][1];
                break;
            }
            
            if(row>=0)
            {
                for(int t=tempColumn; t>=0; t--)
                {
                    arr[tempRow][t] = arr[tempRow+1][t] + arr[tempRow][t+1];     
                }
                
                if(row>0)
                row--;
                
            }
            
            
            if(column>=0)
            {
                for(int t=tempRow; t>=0; t--)
                {
                    arr[t][tempColumn] = arr[t][tempColumn+1] + arr[t+1][tempColumn];     
                }
                if(column>0)
                column--;
                
            }
            
            
            
        }
        
        return arr[0][0];
        
    }
};