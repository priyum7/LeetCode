class Solution {
public:
    bool rotateString(string A, string B) {
        
        if(A==B)
            return true;
        
        if(A.size()!=B.size())
        return false;
        
        
        int left=0;
        while(left<A.size())
        {
            if(A.substr(left, A.size()-left) + A.substr(0, left) == B)
                return true;
            left++;
        }
        return false;
        
        
    }
};
