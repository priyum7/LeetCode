class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> result;
        int l=0, r=n;
        while(l<n || r<nums.size())
        {
            result.emplace_back(nums[l]);
            result.emplace_back(nums[r]);
            l++;
            r++;
        }
        
        return result;
        
        
    }
};