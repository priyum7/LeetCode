class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> temp;
        
        vector<vector<int>> result;
        
        for(int t=0;t<nums.size();t++)
        {
            int l = t+1;
            int r = nums.size()-1;
            
            
            while(l<r)
            {
                if(nums[l]+nums[r] == 0-nums[t])
                {
                    temp.insert({nums[t], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r] < 0-nums[t])
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            
            
        }
        
        for(auto i = temp.begin(); i!=temp.end(); i++)
        {
            result.push_back(*i);
        }
        
        return result;
        
        
    }
};