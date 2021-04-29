class Solution {
public:
    
    
    bool bfs(vector<vector<int>>& graph, vector<int> &color, queue<pair<int,int>> &nodes)
    {
        while(nodes.size()>0)
        {
            int curr = nodes.front().first;
            int curr_color = nodes.front().second;
            
            nodes.pop();
            
            int next_color = (curr_color+1)%2;
            
            for(int t=0;t<graph[curr].size();t++)
            {
                if(color[graph[curr][t]]!=-1 && color[graph[curr][t]]!=next_color){
                    return false;
                }
                
                if(color[graph[curr][t]]==-1)
                {
                    color[graph[curr][t]] = next_color;
                    nodes.push({graph[curr][t], next_color});
                }
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        
        int n = graph.size();
        queue<pair<int, int>> nodes; 
        
        vector<int> color(n, -1);
        for(int t=0;t<n;t++)
        {
            if(color[t]==-1)
            {
                color[t]=0;
                nodes.push({t ,0});
                if(!bfs(graph, color, nodes))
                    return false;
            }
        }
        return true;
    }
};