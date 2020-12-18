class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> s;
        s.push(asteroids[0]);
        int t=1;
        
        while(t<asteroids.size())
        {
             if(s.size()!=0 && s.top()>0 && asteroids[t]<0)
             {
                 if(s.top()==abs(asteroids[t]))
                 {
                     s.pop();
                     t++;
                 }
                 else if(s.top()>abs(asteroids[t]))
                 {
                     t++;
                 }
                 else
                 {
                     s.pop();
                 }
             }
            else
            {
                s.push(asteroids[t]);
                t++;
            }
        }
        
        vector<int> result;
        
        while(s.size()!=0)
        {
            result.push_back(s.top());
            s.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
