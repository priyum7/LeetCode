class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int t=0;t<nums.size();t++)
        {
            if(nums[abs(nums[t])]>0)
                nums[abs(nums[t])] *= -1;
            else
                return abs(nums[t]);
                
        }
        return 0;
    }
};