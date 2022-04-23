
struct comp{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second; 
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mymap;
        
        for(int t=0;t<arr.size();t++)
        {
            mymap[arr[t]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        for(auto i=mymap.begin(); i!=mymap.end(); i++)
        {
            pq.push(make_pair(i->first, i->second));
        }
        
        int total = arr.size(), curr_count= arr.size();
        int result=0;
        while(curr_count > (total/2))
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            result++;
            curr_count-=temp.second;
        }
        
        return result;
    }
};