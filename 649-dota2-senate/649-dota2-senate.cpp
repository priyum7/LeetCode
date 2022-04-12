class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int r=0, d=0, rr=0, rd=0;
                
        for(int t=0; t<senate.size(); t++)
        {
            if(senate[t] == 'R')
                r++;
            else
                d++;
        }
        
        while(r>0 || d>0)
        {
            
            for(int t=0; t<senate.size(); t++)
            {
                
                if(r==0)
                    return "Dire";
                if(d==0)
                    return "Radiant";
                
                if(senate[t] == 'R')
                {
                    if(rr>0)
                    {
                        senate[t]='X';
                        rr--;
                        r--;
                    }
                    else{
                        rd++;
                    }
                }
                
                if(senate[t] == 'D')
                {
                    if(rd>0)
                    {
                        senate[t]='X';
                        rd--;
                        d--;
                    }
                    else
                    {
                        rr++;
                    }
                }
            
            }
            
        }
        return "";
    }
};