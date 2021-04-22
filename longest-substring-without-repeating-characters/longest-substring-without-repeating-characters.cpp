class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()<=1 )
            return s.length();
        
        
        unordered_map<int,int> hash;
        int tempstart=0;
        int max_length = INT_MIN;
        
        for(int t=0;t<s.size();t++)
        {
            
            
            
                if(hash.count(s[t]) && hash[s[t]]>=tempstart)
            {
                max_length = max(max_length, t-hash[s[t]]);
                    tempstart=hash[s[t]]+1;
                    
            }
            
            
                 max_length = max(max_length, t-tempstart+1);
            
           
            hash[s[t]] = t;
            
            
        }
        
        return max_length;
        
    }
};