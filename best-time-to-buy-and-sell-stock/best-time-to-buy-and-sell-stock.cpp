class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()==0)
            return 0;
        
        
        
        int min = prices[0] ;
        int result = 0;
        
        for(int t=0;t<prices.size();t++)
        {
            if(prices[t]<min)
                min = prices[t];
            
            result=max(result, prices[t]-min);
        }
        return result;
        
    }
};