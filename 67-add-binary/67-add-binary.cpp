class Solution {
public:
    string addBinary(string a, string b) {
        
        int lastinda = a.size()-1;
        int lastindb = b.size()-1;
        
        string result = "";
        
        int carry =0;
        
        while(lastinda >= 0 || lastindb >= 0)
        {
            int curra = 0, currb =0;
            
            if(lastinda >= 0)
                curra = a[lastinda] - '0';
            
            if(lastindb >= 0)
                currb = b[lastindb] - '0';
            
            int sum = curra + currb + carry;
            
            result = (char)('0' + (sum%2)) + result;
            carry = sum >= 2 ? 1 : 0;
            lastinda --;
            lastindb--;
            
        }
        
        if(carry > 0)
            result = (char)('0' + (carry)) + result;
        
        return result;
        
    }
};