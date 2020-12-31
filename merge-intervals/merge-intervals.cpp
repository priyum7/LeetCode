class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0]<b[0];
        
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size()==0)
            return intervals;
        
        sort(intervals.begin(),intervals.end(),comp);
        
        int t=0,n=intervals.size();
        vector<vector<int>> result;
        vector<int> temp;
        temp = intervals[0];
        
        while(t<intervals.size())
        {
            
            if(t==n-1)
            {
                result.push_back(intervals[t]);
                break;
            }
            
            
            if((temp[1]>=intervals[t+1][0] && temp[1]<=intervals[t+1][1]) || temp[1]>intervals[t+1][1])
            {
                temp[1] = max(temp[1],intervals[t+1][1]);
                t++;
                if(t==n-1)
                {
                    result.push_back(temp);
                    break;
                }
            }
            else
            {
                result.push_back(temp);
                temp =  intervals[t+1];
                t++;
            }
        }
        
        return result;
    }
};
