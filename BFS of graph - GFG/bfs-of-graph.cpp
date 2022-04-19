// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        
        queue<int> toVisit;
        
        vector<int> result;
        
        int t=0;
            
            if(visited[t] == 0)
            {   
                toVisit.push(t);
        
            while(!toVisit.empty())
            {
                int curr = toVisit.front();
                toVisit.pop();
                result.push_back(curr);
                
                
                for(int q=0; q<adj[curr].size(); q++)
                {
                    if(visited[adj[curr][q]] == 0)
                    {   
                        toVisit.push(adj[curr][q]);
                        visited[adj[curr][q]] = 1;
                    }
                }
            }
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends