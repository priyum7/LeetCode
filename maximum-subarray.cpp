class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int i=0;
        
        
        int max=nums[0], current_max=0;
        
        while(i<nums.size())
        {
            current_max = current_max + nums[i];
            
            if(max<current_max)
            max = current_max;
            
            if(current_max<0)
                current_max=0;
            
            i++;
        }
        
        return max;
        
    }
};
