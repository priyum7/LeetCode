class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> p;
        
        for(int t=0;t<piles.size();t++)
        {
            p.push(piles[t]);
        }
        
        for(int t=0;t<k;t++)
        {
            int temp = p.top();
            p.pop();
            
            temp = temp - floor(temp/2);
            p.push(temp);
            
        }
        
        int result =0;
        
        while(p.size()>0)
        {
            result += p.top();
            p.pop();
        }
        
        return result;
        
    }
};