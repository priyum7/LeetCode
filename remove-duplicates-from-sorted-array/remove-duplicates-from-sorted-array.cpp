class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int left=0 ,t=0;
        
        if(nums.size()==1)
            return 1;
        
        while(t<nums.size())
        {
            while(t+1<nums.size() && nums[t]==nums[t+1])
            {
                t++;
                
            }
          
            swap(nums[left], nums[t]);
            
            left++;
            t++;
    }
        
    return left;
    }
};