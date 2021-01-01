class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        if(nums.size()<=1)
            return;
        
        int t=nums.size()-2;
​
        int flag=0;
        for(;t>=0;t--)
        {
            
            if(nums[t]<nums[t+1])
            {
                flag=1;
                int minIndex=-1;
                int min=INT_MAX;
                for(int temp=t+1;temp<nums.size();temp++)
                {
                    if(nums[temp]>nums[t] && min>nums[temp])
                    {
                        minIndex=temp;
                        min=nums[temp];
                    }
                }
                swap(nums[t], nums[minIndex]);
                sort(nums.begin()+t+1, nums.end());
                break;
            }
        }
        
        if(flag==0)
        sort(nums.begin(), nums.end());
        
    }
};
