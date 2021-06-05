class AuthenticationManager {
public:
    
    int timeToLive;
    unordered_map<string, int> tokens;
    
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        if(tokens.count(tokenId)==0)
        tokens[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        
        if(tokens.count(tokenId)!=0 && currentTime-tokens[tokenId]<timeToLive)
        tokens[tokenId] = currentTime;
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        
        int count=0;
        // cout<<"timetolive"<<timeToLive<<endl;
        // cout<<"currentTime"<<currentTime<<endl;
        for(auto i=tokens.begin(); i!=tokens.end() ; i++ )
        {
            // cout<<i->first<<" "<<i->second<<endl;
            if(currentTime-i->second<timeToLive)
                count++;
        }
    
        return count;
        
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */