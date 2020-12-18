class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_map<int, int> candyMap;
        int typeCount=0;
        
        for(int t=0;t<candyType.size();t++)
        {
            if(candyMap.count(candyType[t])==0)
            {
                candyMap[candyType[t]]++;
                typeCount++;
            }
        }
        
        if(candyType.size()/2>typeCount)
        {
            return typeCount;
        }
        else
        {
            return candyType.size()/2;
        }
        
    }
};
