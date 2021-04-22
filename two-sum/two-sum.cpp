class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> hash;
        
        for(int t=0;t<nums.size();t++)
        {
            hash[nums[t]]=t;
        }
        
        for(int t=0;t<nums.size();t++)
        {
            if(hash.count(target - nums[t]) && t!=hash[target-nums[t]])
            {
                return {t, hash[target-nums[t]]};
            }
        }
        return {};
    }
};