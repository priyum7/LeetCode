class Solution {
public:
    
    bool sumdividends(vector<int>& nums, int threshold, int div)
    {
        int result=0;
        
        for(int t=0;t<nums.size();t++)
        {
            result = result + ceil((float)nums[t] / div);
        }
        
        return result <= threshold ? true : false;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low=1, high=*max_element(nums.begin(), nums.end());
        int result = 0;
        
        while(low<=high)
        {
            int mid = (low + high)/2;
            
            if(sumdividends(nums, threshold, mid))
            {
                result = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
            
        }
        
        return result;
        
    }
};