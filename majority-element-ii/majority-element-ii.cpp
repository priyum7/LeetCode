class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2;
        
        int c1=0, c2=0;
        
        for(int t=0;t<nums.size();t++)
        {
            if(num1 == nums[t])
                c1++;
            else if(num2 == nums[t])
                c2++;
            else if(c1==0)
            {
                num1 = nums[t];
                c1=1;
            }
            else if(c2==0)
            {
                num2 = nums[t];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
            
        }
        cout<<num1<<endl<<num2<<endl;
        
        c1=0;
        c2=0;
        
        vector<int> result;
        
        for(int t=0;t<nums.size();t++)
        {
            if(num1 == nums[t])
            {
                c1++;
            }
            if(num2 == nums[t])
            {
                c2++;
            }
        }
        
      
        
        if(c1>nums.size()/3)
            result.push_back(num1);
         if(c2>nums.size()/3)
            result.push_back(num2);
        
        return result;
    }
};