class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size()==1)
            return;
        
        int r=nums.size()-1;
        int l=r-1;
        bool decreasing=true;
        
        while(r!=0)
        {
            if(nums[l]<nums[r])
            {
             decreasing = false;
            break;
            }
            l--;
            r--;
        }
        
        
        
        if(decreasing==true)
        {
        l=0;
        r=nums.size()-1;
         while(l<r)
         {
             swap(nums[l], nums[r]);
             l++;
             r--;
         }
        }
        else{
            int min_greater_element = INT_MAX;
            int min_greater_index;
            for(int t=nums.size()-1; t>=r; t--)
            {
                if(nums[l]<nums[t])
                {
                    if(min_greater_element> nums[t])    
                    {min_greater_element =  nums[t];
                        min_greater_index = t;
                    }
                }
            }
            
            swap(nums[l], nums[min_greater_index]);
            l=r;
        r=nums.size()-1;
         while(l<r)
         {
             swap(nums[l], nums[r]);
             l++;
             r--;
         }
        }
        
    }
};