class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int sum=0;
            
        int max_sum=0;
        
        for(int t=0;t<nums.size();t++)
        {
            if(nums[t]==0)
            {
                sum=0;
            }
            else
            {
                sum++;
                max_sum = max(max_sum, sum);
            }
        }
        
        return max_sum;
        
        
    }
};