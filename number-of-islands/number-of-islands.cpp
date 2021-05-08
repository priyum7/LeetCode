class Solution {
public:
    
    
    int find(vector<int> &parent, int index)
    {
        return parent[index] = index != parent[index] ? find(parent, parent[index]) : index;
    }
    
    void union_ds(vector<int> &parent, vector<int> &rank, int l, int r)
    {
        
        int parent_l = find(parent, l);
        int parent_r = find(parent, r);
        
        if(rank[parent_l]>rank[parent_r])
        {
            parent[parent_r] = parent_l;
        }
        else if(rank[parent_l]<rank[parent_r])
        {
            parent[parent_l] = parent_r;
        }
        else
        {
            parent[parent_r] = parent_l;
            rank[parent_l]++;
        }
            
    }
    
    
    int convert_ind(vector<vector<char>>& grid,int i, int j)
    {
        return i*(grid[0].size()) + j;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
    
        vector<int> rank(grid.size()*grid[0].size(), 0);
        
        vector<int> parent(grid.size()*grid[0].size(), 0);
        
        for(int t=0;t<grid.size();t++)
        {
            for(int q=0;q<grid[0].size();q++)
            {
                int i = convert_ind(grid, t,q);
                parent[i] = i;
            }
        }
        
        for(int t=0;t<grid.size();t++)
        {
            for(int q=0;q<grid[0].size();q++)
            {
                if(grid[t][q]=='1')
                {
                    
                    if(q<grid[0].size()-1 && grid[t][q+1]=='1')
                        union_ds(parent, rank, convert_ind(grid, t,q), convert_ind(grid, t,q+1));
                    
                    if(t<grid.size()-1 && grid[t+1][q]=='1')
                        union_ds(parent, rank, convert_ind(grid, t,q), convert_ind(grid, t+1,q));
                }
                else
                {
                    parent[convert_ind(grid, t,q)]=-1;
                }
            }
        }
        
        
//         for(int t=0;t<rank.size();t++)
//         {
//             cout<<rank[t]<<" ";
//         }
        
//         cout<<endl;
       
//         for(int t=0;t<parent.size();t++)
//         {
//             cout<<parent[t]<<" ";
//         }
        
                int count=0;

        
        for(int t=0;t<parent.size();t++)
        {
            if(parent[t] == t && grid[t/(grid[0].size())][t%(grid[0].size())]=='1')
                count++;
        }
        
        
        
        
        
        
        
        return count;
        
        
    }
};