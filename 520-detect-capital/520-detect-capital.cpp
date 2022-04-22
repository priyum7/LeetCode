class Solution {
public:
    bool detectCapitalUse(string word) {
        int capcount=0;
        bool first=false;
        
        for(int t=0;t<word.size();t++)
        {
            if(word[t]>='A' && word[t]<='Z')
            {
                if(t==0)
                    first=true;
                capcount++;
            }
        }
        
        return (capcount==word.length() || capcount==0 || (capcount == 1 && first==true));
        
    }
};