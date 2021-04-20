class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool iscol=false;
        bool isrow=false;
        
        for(int i=0;i<matrix.size();i++)
        {
           for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0 || j==0)
                    {
                        if(i==0 && j==0)
                        {
                            isrow=true;
                            iscol=true;
                        }
                        else if(i==0)
                        {
                            isrow=true;
                            matrix[0][j]=0;
                        }
                        else
                        {
                            iscol=true;
                            matrix[i][0]=0;        
                        }
                    }
                    else
                    {
                    
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    }
                }
            } 
        }
        
        for(int i=matrix[0].size()-1; i>0; i--)
        {
            if(  matrix[0][i]==0)
            {
           for(int j=0; j<matrix.size(); j++)
           {
               matrix[j][i]=0;
           }
            }
        }
        
        
        for(int i=matrix.size()-1;i>=0;i--)
        {
            if((i==0 && isrow) || matrix[i][0]==0)
            {
               for(int j=0; j<matrix[0].size(); j++)
               {
                   matrix[i][j]=0;
               }
            }
        }
        
        if(iscol)
        {
            for(int j=0; j<matrix.size(); j++)
           {
               matrix[j][0]=0;
           }
        }
        
        
        
    }
};