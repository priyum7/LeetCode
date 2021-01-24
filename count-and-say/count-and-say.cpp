class Solution {
public:
    string countAndSay(int n) {
        string start="1";
        int c=1;
        while(c<n)
        {
            string next = "";
            int t=0;
            while(t<start.size())
            {
                int count=1;
                int tempIndex = t;
                t++;
                while(t<start.size() && start[t-1] == start[t])
                {
                    count++;
                    t++;
                }
                
                next = next + (char)('0'+count) + start[tempIndex];
            }
            
            start = next;
            c++;
        }
        return start;
    }
};
