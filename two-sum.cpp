class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hash;
        
        for(int t=0;t<nums.size();t++)
        {
            hash[nums[t]]=t;
        }
        
        vector<int> result;
        
        for(int t=0;t<nums.size();t++)
        {
            if(hash.count(target-nums[t]) && t!=hash[target-nums[t]])
            {
                result = {hash[target-nums[t]], t};
                break;
            }
        }
        
        return result;     
    }
};
