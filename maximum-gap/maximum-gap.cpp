class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        
        if(nums.size()<2)
            return 0;
​
        
        int maxGap=INT_MIN;
        sort(nums.begin(), nums.end());
        for(int t=0;t<nums.size()-1;t++)
        {
            maxGap = max(maxGap, abs(nums[t]-nums[t+1]));
        }
        
        return maxGap;
        
    }
};
