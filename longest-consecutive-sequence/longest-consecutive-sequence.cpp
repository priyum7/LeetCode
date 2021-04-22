class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> visited;
        unordered_map<int, int> hash;
        
        
        if(nums.size()==0)
            return 0;
        
        for(int t=0;t<nums.size();t++)
        {
            hash[nums[t]]++;
        }
        
        int max_length = INT_MIN;
        
        for(int t=0;t<nums.size();t++)
        {
            if(visited.count(nums[t])==0)
            {
                
                int temp_seq_length = 1;
                
                visited[nums[t]]++;
                
                int temp_element=nums[t]-1;
                
                while(hash.count(temp_element))
                {
                    temp_seq_length++;
                    visited[temp_element]++;
                    temp_element--;
                }
                
                temp_element = nums[t]+1;
                
                while(hash.count(temp_element))
                {
                    temp_seq_length++;
                    visited[temp_element]++;
                    temp_element++;
                }
                
                if(max_length<temp_seq_length){
                    max_length = temp_seq_length;
                }
            }
        }
        
        return max_length;
                
    }
};