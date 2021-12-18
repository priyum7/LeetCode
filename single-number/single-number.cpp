class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int t=0;t<nums.size();t++)
        {
            result = result ^ nums[t];
        }
        return result;
    }
};