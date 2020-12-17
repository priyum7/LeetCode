class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        
        int lastSearchChar = searchWord[searchWord.size()-1];
        int i=0;
        int startInd=-1;
        int wordCount=1;
        
        int sentenceN = sentence.size();
        while(i<sentenceN)
        {
            if(sentence[i]==' ')
            {   
                startInd = i;
                wordCount++;
            }
            else if(sentence[i]==lastSearchChar)
            {
                string temp = sentence.substr(startInd+1, i-startInd);
                
                if(temp==searchWord)
                {
                    return wordCount;   
                }
            }
            i++;
            
            
        }
        
        return -1;
    }
};
