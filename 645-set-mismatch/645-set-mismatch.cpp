class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mymap;
        
        for(int t=0;t<nums.size();t++)
        {
            mymap[nums[t]]++;
        }
        
        int dup, mis;
        
        for(int t=1;t<=nums.size();t++)
        {
            if(mymap[t] == 0)
                mis = t;
            
            if(mymap[t] > 1 )
                dup = t;
        }
        
        return { dup, mis };
    }
};