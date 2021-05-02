class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        for(int t=0;t<nums.size();t++)
        {
            if(t>0 && nums[t]==nums[t-1])
            {
                continue;    
            }
            
            for(int q=t+1;q<nums.size();q++)
            {
                
                if(q>t+1 && nums[q]==nums[q-1])
                    continue;
                
                int l = q+1;
                int r = nums.size()-1;
                
                while(l<r)
                {
                    if(nums[l]+nums[r] == target - nums[t] - nums[q])
                    {
                        // cout<<"t:"<<t<<" q:"<<q<<" l:"<<l<<" r:"<<r<<endl;
                        result.push_back({nums[t],nums[q],nums[l],nums[r]});
                        l++;
                        r--;
                        while(r>=l && nums[r]==nums[r+1])
                        {
                            r--;
                        }
                    }
                    else if(nums[l]+nums[r] < target - nums[t] - nums[q])
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                        while(r>=l && nums[r]==nums[r+1])
                        {
                            r--;
                        }
                    }
                }
                
            }
            
            
        }
        return result;
        
    }
};