class Solution {
public:
    
    bool helper(vector<int>& nums, int i, unordered_map<int, int> &visited)
    {
        unordered_map<int, int> mymap;
        vector<int> index_array;
        bool result=false;
        int count=0;
        int prev;
        
        while(true)
        {
            
            index_array.push_back(i);
            cout<<i;
            
            if(mymap[i]>0)
            {
                int forward_steps=0;
                int backward_steps=0;
                int loop_length=0;
                int search_element = i;
                int n = index_array.size()-2;
                cout<<endl<<"size"<<n<<endl;
                while(true)
                {
                    loop_length++;
                    
                    cout<<endl<<"xxxxxx"<<nums[n]<<"xxxxx"<<endl;
                    if(nums[index_array[n]]>0)
                        forward_steps++;
                    else
                        backward_steps++;
                    
                    if(index_array[n]==search_element)
                    break;
                        
                    n--;
                }
                cout<<endl<<forward_steps<<" "<<backward_steps<<" "<<loop_length<<endl;
                if(loop_length>1 && (forward_steps==0 || backward_steps==0))
                    return true;
                else
                    return false;
                
            }
            
            if(count==nums.size())
                break;
