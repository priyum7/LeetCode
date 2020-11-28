class Solution {
public:
    int fib(int N) {
        
        if(N==0)
            return 0;
        
        int index = 1;
        
        int first=0, second=1;
        
        
        
        while(index<N)
        {
            int temp = first + second;
            first = second;
            second = temp;
            index++;
        }
        
        return second;
    }
};
