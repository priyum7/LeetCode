class Solution {
public:
    
    
    int find(int index, vector<int> &parent)
    {
        if(index==parent[index])
            return index;
        
        return parent[index] = find(parent[index], parent);
    }
    
    bool unionop(int i, int j, vector<int> &parent, vector<int> &rank)
    {
        int parentI = find(i, parent);
        int parentJ = find(j, parent);
        
        if(parentI!=parentJ)
        {
            if(rank[parentI]>rank[parentJ])
            {
                parent[parentJ] = parentI;
            }
            else if(rank[parentI]<rank[parentJ])
            {
                parent[parentI] = parentJ;
            }
            else
            {
                rank[parentI]++;
                parent[parentJ] = parentI;
            }
            return false;
        }
        else
            return true;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(edges.size()+1);
        vector<int> rank(edges.size()+1,0);
        
        vector<int> result;
        
        for(int t=1;t<=edges.size();t++)
        {
            parent[t]=t;
        }
        
        for(int t=0;t<edges.size();t++)
        {
            // cout<<parent[t];
            if(unionop(edges[t][0], edges[t][1], parent, rank))
                result = edges[t];
        }
        
        return result;
        
    }
};