class Solution {
public:
    bool isValid(string s) {
        
        stack<int> st;
        
        for(int i=0; i<s.size(); i++)
        {
            if(st.size()==0)
            {
                st.push(s[i]);
                continue;
            }
            
            if(st.top()=='(' && s[i]==')')
            {
                st.pop();
                continue;
            }
            
            if(st.top()=='[' && s[i]==']')
            {
                st.pop();
                continue;
            }
            
            if(st.top()=='{' && s[i]=='}')
            {
                st.pop();
                continue;
            }
            
            st.push(s[i]);
            
        }
        
        if(st.size()==0)
            return true;
        else
            return false;
        
    }
};
