class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=0,max=INT_MIN,negativeMax=INT_MIN;
        
        
        
        for(int t=0;t<nums.size();t++)
        {
            sum+=nums[t];
            
            if(sum<0)
            {
                sum=0;
            }
            
            if(max<sum)
                max=sum;
            
            if(negativeMax<nums[t])
                negativeMax=nums[t];
            
        }
​
        
        return max==0 ? negativeMax : max;
        
    }
};
