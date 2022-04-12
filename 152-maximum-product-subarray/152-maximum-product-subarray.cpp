class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma=nums[0], mi=nums[0], res=nums[0];
        
        for(int t=1;t<nums.size();t++)
        {
            if(nums[t]<0)
                swap(ma, mi);
            
            ma = max(nums[t], ma*nums[t]);
            mi = min(nums[t], mi*nums[t]);
                        
            res = max(res, max(ma, mi));
        }
        
        return res;
        
    }
};