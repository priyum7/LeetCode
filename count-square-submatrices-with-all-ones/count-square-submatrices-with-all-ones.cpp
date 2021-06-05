class Solution {
public:
    
 
    
    
    int countSquares(vector<vector<int>>& matrix) {
        
        int sums[matrix.size()][matrix[0].size()];
        
        int sum=0;
        
        for(int t=0;t<matrix.size();t++)
        {
            sum +=matrix[t][0];
            sums[t][0] = sum;
        }
        
                sum=0;

        
        for(int t=0;t<matrix[0].size();t++)
        {
            sum+=matrix[0][t];
            sums[0][t] = sum;
        }
        

         
        
        for(int t=1; t<matrix.size(); t++)
        {
            for(int q=1; q<matrix[0].size(); q++)
            {
                sums[t][q] = matrix[t][q] + sums[t-1][q] +sums[t][q-1] - sums[t-1][q-1];    
            }   
        }
        
        int m = min(matrix.size(), matrix[0].size());
           
        int count=0;
//          for(int t=0; t<matrix.size(); t++)
//         {
//             for(int q=0; q<matrix[0].size(); q++)
//             {
//                 cout<<sums[t][q];    
//             }   
             
//              cout<<endl;
//         }

        
        
            
        for(int x=0; x<m; x++)
        {                        

            for(int a=0;a+x<matrix.size(); a++)
            {
                for(int b=0;b+x<matrix[0].size(); b++)
                {
                        int lx=a, ly=b, tx=a+x, ty=b+x;   
                      int top=0, left=0, inter=0;
        
                    if(lx-1>=0)
                        top = sums[lx-1][ty];

                    if(ly-1>=0)
                        left = sums[tx][ly-1];

                    if(lx-1>=0 && ly-1>=0)
                        inter = sums[lx-1][ly-1];

                    // cout<<sums[tx][ty] - top - left + inter<<" ";
                    
                    if((x+1)*(x+1) == sums[tx][ty] - top - left + inter)
                        count++;
                }
                // cout<<endl;
            }
        }
        
        return count;
        
        
        
    }
};