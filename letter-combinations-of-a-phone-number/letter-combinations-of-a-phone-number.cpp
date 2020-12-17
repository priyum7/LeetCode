class Solution {
public:
    
    vector<string> result;
    
    vector<string> keypad = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void helper(string digits, string temp="")
    {
        if(digits.size()==0)
        {
            result.push_back(temp);
            return;
        }
        
        int index = digits[0]-'2';
        for(int t=0;t<keypad[index].size();t++)
        {
            helper(digits.substr(1), temp + keypad[index][t]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits=="")
        {
            return {};
        }
        helper(digits);
        return result;
    }
};
