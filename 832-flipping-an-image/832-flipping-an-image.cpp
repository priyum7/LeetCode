class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int t=0;t<image.size();t++)
        {
            int start=0, end=image[0].size()-1;
            while(start<=end)
            {
                swap(image[t][start], image[t][end]);
                image[t][start] = (image[t][start]+1)%2;
                if(start!=end)
                image[t][end] = (image[t][end]+1)%2;
                start++;
                end--;
            }
        }
        return image;
    }
};