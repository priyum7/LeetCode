class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int curr=-1;
        
        double result=0;
        
        for(int t=0;t<customers.size();t++){
            
            curr = max(curr, customers[t][0]);
            
            curr+=customers[t][1];
            
            result+= curr-customers[t][0];
            
            
        }
        
        return result/customers.size();
        
        
    }
};