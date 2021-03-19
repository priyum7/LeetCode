class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> hash(nums.size(), -1);
        
        for(int t=0;t<nums.size(); t++)
        {
            if(hash[nums[t]]==-1)
            {
                hash[nums[t]]++;
                
            }
            else if(hash[nums[t]]==0)
            {
                return nums[t];
            }
            
        }
        return 0;
    }
};