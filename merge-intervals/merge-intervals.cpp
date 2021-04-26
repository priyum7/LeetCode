class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]<b[0])
            return true;
        else
            return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
    sort(intervals.begin(), intervals.end(), comp);
        
        
    vector<vector<int>> result;        
    stack<vector<int>> s;
        
    for(int i=0;i<intervals.size();i++)
    {
        int left ,right;
        vector<int> curr = intervals[i];
        while(!s.empty() && ( s.top()[1]>=curr[0] || s.top()[1]>=curr[1]))
        {
            vector<int> temp = s.top();
            s.pop();
            left = min(temp[0], curr[0]);
            right = max(temp[1], curr[1]);
            curr = {left,right};
        }
        
        s.push(curr);
        
    }
        
        while(s.size()!=0)
        {
            result.push_back(s.top());
            s.pop();
        }
        
        
        return result;;
    }
};