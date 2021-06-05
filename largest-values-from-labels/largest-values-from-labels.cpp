
class item{
    public:
    int val;
    int label;
    
    item()
    {}
    
    item(int val, int label)
    {
        this->val=val;
        this->label=label;
    }
};

class Solution {
public:
    
    static bool comp(item i1, item i2){
        return i2.val>i1.val ? false: true; 
    }
    
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        
        
        vector<item> items(values.size());
        
        for(int t=0;t<values.size();t++)
        {
            items[t] = item(values[t], labels[t]);
        }
        
        sort(items.begin(), items.end(), comp);
        
        
        unordered_map<int, int> labelcount;
        
        
          
//         for(int t=0;t<values.size();t++)
//         {
//             cout<<items[t].val<<endl;
//         }
        
        
        int result=0,count=0;
        
        for(int t=0;t<values.size();t++)
        {
            
            if(labelcount[items[t].label]<use_limit)
            {
                count++;
                result+=items[t].val;
                labelcount[items[t].label]++;
            }
            
            
            if(count==num_wanted)
                break;
        }
        
    return result;
        
    }
};