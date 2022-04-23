class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int result=INT_MAX;
        int targetint = (int)target;
        
        for(int t=0; t<letters.size(); t++)
        {
            int currchar = (int)letters[t];
            if(targetint < currchar)
            {
                result = min(result, currchar);
            }
            else
            {
                result = min(result, currchar+26);
            }
        }
        
        return result>(int)('z') ? (char)(result - 26) : (char)result;
        
        
    }
};