class Solution {
public:
    
    vector<vector<int>> result;
    
    void helper(vector<int>& nums, unordered_map<int,int> mymap, vector<int> temp={})
    {
        if(temp.size()>nums.size())
        {
            return;
        }
        
        if(temp.size()==nums.size())
        {
            result.push_back(temp);
        }
        
        for(int t=0;t<nums.size();t++)
        {
            if(mymap[t]==0)
            {
            temp.push_back(nums[t]);
            mymap[t]=1;
            helper(nums, mymap, temp);
            mymap[t]=0;
            temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums)
    {
        unordered_map<int,int> mymap;
        helper(nums, mymap);
        return result;
    }
};
