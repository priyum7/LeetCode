class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int, vector<int>> em_list;
        
        for(int t=0;t<n;t++)
        {
            em_list[manager[t]].push_back(t);
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(headID,0));
        
        long long int result =0;
        
        while(!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            
            if(em_list[curr.first].size()>0)
            {
                for(int s=0;s<em_list[curr.first].size();s++)
                {
                    q.push(make_pair(em_list[curr.first][s], curr.second+informTime[curr.first]));
                    
                    if(result<curr.second+informTime[curr.first])
                        result = curr.second+informTime[curr.first];
                }
                
            }
            
        }
        return result;
    }
};