class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &result, vector<int> temp={}, int i=0) {
        
        
        if(i==nums.size())
        {
            result.push_back(temp);
            return ;
        }
        
       
            helper(nums, result, temp, i+1);
            temp.push_back(nums[i]);
            helper(nums, result, temp, i+1);
                
    }
    
vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    helper(nums, result);
    return result;
}
    
};
