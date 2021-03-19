class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        int left=0, right=nums.size()-1;
        if(right==0)
            return;
        while(left<nums.size() && nums[left]==0)
        {
            left++;
        }
        
        while(right>=0 && nums[right]==2)
        {
            right--;
        }
        
        int t=left;
        
        while(t<=right)
        {
            if(nums[t]==0)
            {
                swap(nums[t], nums[left]);
                
                    left++;
                if(t>=left)
                    continue;
                
                    
                
            }
            else if(nums[t]==2)
            {
                swap(nums[t], nums[right]);
                
                    right--;
                if(t<=right)
                    continue;
                
            }
            t++;
        }
    }
};