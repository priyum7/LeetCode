class Solution {
public:
    
    void helper(list<pair<int, int>> &dq, int currind, int currval, int startindex)
    {
        
        if(!dq.empty() && dq.front().second < startindex)
            dq.pop_front();
        
        while(!dq.empty() && dq.back().first<currval){
            dq.pop_back();
        }
        
        dq.push_back(make_pair(currval, currind));
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> result;
        list<pair<int, int>> dq;
        
        
        for(int t=0;t<k; t++)
        {
            helper(dq, t, nums[t], 0);
        }
        result.push_back(dq.front().first);
        for(int t=k; t<nums.size(); t++)
        {
            helper(dq, t, nums[t], t-k+1);
            result.push_back(dq.front().first);
        }
        
        return result;
    }
};