class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size() ;
        
        int tempIndex = nums.size()-k;
        
        vector<int> tempVector;
        
        while(tempIndex<nums.size())
        {
            tempVector.push_back(nums[tempIndex]);
            tempIndex++;
        }
        
        tempIndex = nums.size()-k-1;
        
        while(tempIndex>=0)
        {
            nums[tempIndex+k] = nums[tempIndex];
            tempIndex--;
        }
        
        for(tempIndex=0;tempIndex<tempVector.size();tempIndex++)
        {
            nums[tempIndex] = tempVector[tempIndex];
        }
        
        
        
        
        
    }
};
