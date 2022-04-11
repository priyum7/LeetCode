class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<long, int> mymap;
        
        for(int t=0; t<nums.size(); t++)
        {
            mymap[stol(nums[t], 0, 2)]++;
        }
        
        long long int limit = pow(2, nums.size()+1)-1;
        for(long long int t=0; t<=limit; t++)
        {
            if(!mymap.count(t))
            {
                int i = nums.size() - 1;
                string res = "";
                while(i>=0)
                {
                    res = res + (((t & (1<<i)) > 0) ? "1" : "0");
                    i--;
                }
                return res;   
            }
        }
        return "";
         
    }
};