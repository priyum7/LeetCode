class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> mymap;
        
        for(int t=0;t<word1.length();t++)
        {
            mymap[word1[t]]++;
        }
        
        for(int t=0;t<word2.length();t++)
        {
            mymap[word2[t]]--;
        }
        
        for(auto t=mymap.begin(); t!=mymap.end(); t++)
        {
            if(abs(t->second)>3)
                return false;
        }
        
        return true;
    }
};