class Solution {
public:
    
    
    int findparent(int i, vector<int> &parent)
    {
        if(parent[i] == i)
            return i;
        
        return parent[i] = findparent(parent[i], parent);
    }
    
    void unionOP(int i, int j, vector<int> &parent, vector<int> &rank){
        
     int parenti = findparent(i, parent);
        int parentj = findparent(j, parent);
        
        
        if(parenti==parentj)
            return;
        
        if(rank[parenti]<rank[parentj])
            parent[parenti] = parentj;
        else if(rank[parenti]>rank[parentj])
            parent[parentj] = parenti;
        else
        {parent[parenti]=parentj;
        rank[parentj]++;
        }
    
        
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        
        vector<int> parent(isConnected.size());
        
        for(int t=0;t<isConnected.size();t++)
        {
            parent[t] = t;
        }
        
        vector<int> rank(isConnected.size(),0);
        
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j]==1)
                {unionOP(i,j,parent, rank);
                 //unionOP(j,i,parent, rank);
                }
            }
        }
        
        
        int result=0;
        
        for(int t=0;t<parent.size();t++){
            
            //cout<<t<<" "<<parent[t]<<endl;
            
            if(parent[t]==t)
                result++;
            
        }
        
        return result;
    }
};