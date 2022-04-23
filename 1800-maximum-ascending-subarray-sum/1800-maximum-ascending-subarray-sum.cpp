class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currsum=nums[0], result=nums[0];
        
        for(int t=1; t<nums.size(); t++)
        {
            if(nums[t-1] < nums[t])
            {
                currsum+=nums[t];
                result = max(result, currsum);
            }
            else
            {
                currsum = nums[t];
            }
        }
        
        return result;
        
    }
};