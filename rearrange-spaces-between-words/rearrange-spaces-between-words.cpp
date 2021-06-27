class Solution {
public:
    string reorderSpaces(string text) {
        
        
        string result="";
        bool isWord = false;
        
        int words=0,blanks=0;
        
        for(int t=0;t<text.size();t++)
        {
            if(text[t]>='a' && text[t]<='z')
            {
                isWord=true;
            }
            else
            {
                blanks++;
                if(isWord)
                {
                    isWord=false;
                    words++;
                }
            }
        }
        
        if(text[text.size()-1]!=' ')
        {
            words++;
        }
        
        int spaceBetweenWords;
        if(words>1)
        spaceBetweenWords = blanks/(words-1);
        else
        spaceBetweenWords=0;    
        
        
        int currwords=0;
        isWord = false;
        for(int t=0;t<text.size() && currwords<words;t++)
        {
            if(text[t]>='a' && text[t]<='z')
            {
                isWord=true;
                result = result + text[t];
            }
            else
            {
                if(isWord)
                {   currwords++;
                    if(currwords==words)
                        break;
                 
                    isWord=false;
                    for(int q=0;q<spaceBetweenWords;q++)
                    {
                        result=result+" ";
                    }
                }
            }
        }
        
        blanks = blanks-(spaceBetweenWords*(words-1));
        for(int q=0;q<blanks;q++)
                    {
                        result=result+" ";
                    }
        return result;
        
    }
};