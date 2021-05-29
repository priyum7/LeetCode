class Solution {
public:
    
    int findparent(int child, vector<int> &parent)
    {
        
        if(parent[child] == child)
            return child;
        
        return parent[child] = findparent(parent[child], parent);
    }
    
    void union_ds(int i, int j, vector<int> &rank, vector<int> &parent)
    {
        int parent1 = findparent(i, parent);
        int parent2 = findparent(j, parent);
        
        
        if(parent1==parent2)
            return;
        
        if(rank[parent1]>rank[parent2])
            parent[parent2] = parent1;
        else if(rank[parent1]<rank[parent2])
            parent[parent1] = parent2;
        else
        {
            rank[parent1]++;
            parent[parent2] = parent1;
        }
        return;
    }
    
    

    
    
    int removeStones(vector<vector<int>>& stones) {
        
        
        
            
      
        
         vector<int> rank(stones.size() +1, 0);
         vector<int> parent(stones.size(), 0);
        
        for(int t=0;t<stones.size();t++)
        {
            parent[t] = t;
        }
        
        

        
        unordered_map<int, int> row;
        unordered_map<int, int> column;
        
        for(int t=0;t<stones.size();t++)
        {   
            if(row.count(stones[t][0])==0)
                row[stones[t][0]] = t;
            else
            {
                union_ds(row[stones[t][0]], t, rank, parent);
            }
            
            if(column.count(stones[t][1])==0)
                column[stones[t][1]] = t;
            else
            {
                union_ds(column[stones[t][1]], t, rank, parent);
            }
                
        }
        
        

        
        int result=parent.size();
        
        for(int t=0;t<parent.size();t++)
        {
            if(parent[t]==t)
                result--;
        }

        
        
       

        
        return result;
        
        
    }
};

