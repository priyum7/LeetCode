// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int curr, vector<int> *adj, vector<int> &visited, vector<int> &result)
    {
        if(visited[curr]==1)
        return;
        
        result.push_back(curr);
        visited[curr] = 1;
        
        for(int t=0;t<adj[curr].size(); t++)
        {
            dfs(adj[curr][t], adj, visited, result);
        }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> result;
        
        vector<int> visited(V, 0);
        
        for(int t=0;t<V;t++)
        {
            if(visited[t] == 0)
            dfs(t,adj, visited, result);
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends