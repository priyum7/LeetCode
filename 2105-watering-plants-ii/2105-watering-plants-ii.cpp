class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    
    int fillA=0, fillB=0;
    int i=0, j=plants.size()-1;
    int result=0;
    while(i<=j)
    {
        if(i==j){
            if(plants[i] <= capacityA - fillA || plants[i] <= capacityB - fillB)
                return result;
            else
                result++;
            i++;
            j--;
        }
        else
        {
            if(fillA + plants[i] <= capacityA)
            {   
                fillA+=plants[i];
            }
            else
            {
                result++;
                fillA=plants[i];
            }
            i++;
            
            if(fillB + plants[j] <= capacityB)
            {                                   
                fillB+=plants[j];
            }
            else
            {
                result++;
                fillB=plants[j];
            }
            j--;

        }
    }
        
    return result;
        
    }
};