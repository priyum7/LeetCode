class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        if(nums.size()==0)
            return 0;
        
        unordered_map<int, int> mymap;
        
        for(int t=0; t<nums.size(); t++)
        {
            mymap[nums[t]]=0;
        }
        
        int result = INT_MIN;
        
        for(int t=0; t<nums.size(); t++)
        {
           if( mymap[nums[t]]==0)
           {
               mymap[nums[t]]=1;
               int temp = nums[t];
               int count=1;
               while(mymap.count(--temp) && mymap[temp]==0)
               {
                   mymap[temp]=1;
                   count++;
               }
               temp = nums[t];
               while(mymap.count(++temp) && mymap[temp]==0)
               {
                   mymap[temp]=1;
                   count++;
               }
                if(count>result)
                result=count;
           }
​
           
        }
        
        return result;
        
        
    }
};
