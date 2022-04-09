class Solution {
public:
    
    int strNum(string num){
        
        int res = 0;
        
        while(num.length()>0)
        {
            res = res * 10 + (num[0] - '0');
            num = num.substr(1);
        }
        
        return res;
        
    }
    
    bool checktime (string last, string curr)   
    {
        int lasthour = strNum(last.substr(0,2));
        int currhour = strNum(curr.substr(0,2));
        
        int lastminutes = strNum(last.substr(3,5));
        int currminutes = strNum(curr.substr(3,5));
        
        int updatedlasthour = (lasthour+1)%25;
        
        if(lasthour == currhour && currminutes >=lastminutes)
            return true;
        
        if(updatedlasthour == currhour && currminutes<=lastminutes)
            return true;
        
        return false;
        
    }
    
    
    bool checkAlert(string last, string curr)
    {   
        return checktime(last, curr);
    }
    
    class KeyLog{
        public:
        string name;
        string time;
        
        KeyLog(string x, string y)
        {
            this->name = x;
            this->time = y;
        }
    };
    
    struct comp{
      bool operator()(KeyLog x, KeyLog y)
        {
          
            return x.name < y.name || (x.name == y.name && x.time<=y.time);
        }  
    };
    
    
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        
        vector<KeyLog> keyEntry;
        
        for(int t=0;t<keyName.size();t++)
        {
            KeyLog temp(keyName[t], keyTime[t]);
            keyEntry.push_back(temp);
        }
        
        sort(keyEntry.begin(), keyEntry.end(), comp());
        
        for(int t=0;t<keyName.size();t++)
        {
            cout<<keyEntry[t].name<<" "<<keyEntry[t].time<<endl;
        }
        
        unordered_map<string, bool> userAlerted;
        set<string> result;
        
        for(int t=0;t<keyEntry.size();t++)
        {
                if(userAlerted.count(keyEntry[t].name))
                    continue;
            
                if(t+2<keyEntry.size() && keyEntry[t+2].name == keyEntry[t].name && checkAlert(keyEntry[t].time, keyEntry[t+2].time))
                {   
                        result.insert(keyEntry[t].name);
                        userAlerted[keyEntry[t].name] = true;
                }
                    
        }
        
        vector<string> names;
        
        for(auto i = result.begin(); i!=result.end(); i++)
        {
            names.push_back(*i);
        }
        
        return names;
        
        
    }
};