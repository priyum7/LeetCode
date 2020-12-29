class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int t=0;t<nums.size()-1;t++)
        {
            if(nums[t]==nums[t+1])
                return nums[t];
        }
        return 0;
    }
};
