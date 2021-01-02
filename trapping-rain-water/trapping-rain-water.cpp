class Solution {
public:
    int trap(vector<int>& height) {
        
        int left[height.size()], right[height.size()];
        
        int maxheight=0;
        for(int t=0;t<height.size();t++)
        {
            left[t] = maxheight;
            maxheight=max(maxheight,height[t]);    
        }
        
        maxheight=0;
        for(int t=height.size()-1;t>=0;t--)
        {
            right[t] = maxheight;
            maxheight=max(maxheight,height[t]);    
        }
        
        int waterCount=0;
        for(int t=0;t<height.size();t++)
        {
            int temp =min(left[t],right[t])-height[t];
            if(temp>0)
                waterCount+=temp;
        }
        return waterCount;
​
        
        
        
    }
};
