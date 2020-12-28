class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int left=0,right=nums.size()-1;
        int i=0;
        while(i<=right)
        {
            if(nums[i]==0)
            {
                while(left<=right && nums[left]==0)
                {
                    left++;
                }
                
                if(left<i)
                {
                    int temp = nums[left];
                    nums[left] = nums[i];
                    nums[i] = temp;
                    continue;
                }
            }
            
            else if(nums[i]==2)
            {
                while(right<nums.size() && nums[right]==2)
                {
                    right--;
                }
                
                if(right>i)
                {
                    int temp = nums[right];
                    nums[right] = nums[i];
                    nums[i] = temp;
                    continue;
                }
            }
            
  
            i++;
​
            
        }
        
    }
};
