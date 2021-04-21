class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int majority_ele;
        int count=0;
        
        for(int t=0;t<nums.size();t++)
        {
            if(count==0)
            {
                majority_ele = nums[t];
            }
            
            if(nums[t] != majority_ele)
            {
                count--;
            }
            else
            {
                count++;
            }
            
            
        }
        
        return majority_ele;
    }
};