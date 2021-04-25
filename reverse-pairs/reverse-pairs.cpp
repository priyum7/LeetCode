class Solution {
public:
    
    void helper(vector<int>& nums, int left, int right, int &count)
    {
        if(left==right)
            return;
        
        if(left<right)
        {
            int mid = (left+right)/2;
            
            helper(nums, left, mid, count);
            helper(nums, mid+1,right, count);
            
            vector<int> arr;
            
            int l = left;
            int r= mid+1;
            
            int j=r;
            
            for (int i = l; i <= mid; i++) {
            while (j <= right && nums[i] > nums[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
            
            while(l<=mid && r<=right)
            {
                if(nums[l]<=nums[r])
                {
                    arr.push_back(nums[l]);
                    l++;
                }
                else
                {
                  
                    arr.push_back(nums[r]);
                    r++;
                }
            }
            
            
            while(l<=mid)
            {
                arr.push_back(nums[l]);
                    l++;
            }
            
            while(r<=right)
            {
                
                arr.push_back(nums[r]);
                    r++;
            }
            
            int index=0;
            
            for(int t=left;t<=right;t++)
            {
                nums[t] = arr[index];
                index++;
            }
        }
        }
    
    
    int reversePairs(vector<int>& nums) {
        
        int count=0;
        helper(nums, 0, nums.size()-1, count);
        return count;
        
    }
};