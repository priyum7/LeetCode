class Solution {
public:
    int helper(vector<int>& nums, int target, int start, int end)
    {
        
        int mid = (start+end)/2;
        
        if(nums[mid] == target)
            return mid;
        
        if(start>=end)
            return -1;
        
        int result;
        
        if(target<nums[mid])
        result = helper(nums, target, start, mid-1);
        else
        result = helper(nums, target, mid+1, end);
        
        return result;
    }
    
    int search(vector<int>& nums, int target) {
    return helper(nums, target, 0, nums.size()-1);
    }
};
