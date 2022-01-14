class Solution {
public:
    string reverseStr(string s, int k) {
        
        for(int t=0; t<s.length(); t=t+(2*k))
        {
            if(t+k>s.length())
            {
                k = s.length() - t;
            }
            for(int a=t, b=t+k-1; a<b; a++, b--)
            {
                swap(s[a], s[b]);
            }
        }
        
        return s;
    }
};