class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> left_max(height.size(),0);
        vector<int> right_max(height.size(), 0);
        
        
        int heightMax=0;
        for(int t=0;t<height.size();t++)
        {
            left_max[t] = heightMax;
            heightMax = max(heightMax, height[t]);
        }
        
     heightMax=0;
        for(int t=height.size()-1;t>=0;t--)
        {
            right_max[t] = heightMax;
            heightMax = max(heightMax, height[t]);
        }
        
        int result = 0;
        
        for(int t=0;t<height.size();t++)
        {
            int temp = min(left_max[t],right_max[t])-height[t];
            // cout<<temp<<" ";
            if(temp>0)
            {
                result+=temp; 
            }
        }
        return result;
    }
};