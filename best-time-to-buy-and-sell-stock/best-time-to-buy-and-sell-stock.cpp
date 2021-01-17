class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        if(n==1)
            return 0;
        
       int left=INT_MAX, right=0;
        int t=0;
        while(t<prices.size())
        {
            if(left>prices[t])
            {   
                int currLeft=prices[t];
                cout<<currLeft;
                t++;
                int currRight=currLeft;
                while( t<n && prices[t]>=currLeft)
                {
                    currRight = max(currRight, prices[t]);
                    t++;
                }
                cout<<" "<<currRight<<endl;
                if(right-left<currRight-currLeft)
                {
                    left=currLeft;
                    right=currRight;
                }
            }
            else
            t++;
        }
        
        if(right==0)
            return 0;
        else return right-left;
        
    }
};
