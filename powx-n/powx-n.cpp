class Solution {
public:
    
    
    double helper(double x, long long int n)
    {
        if(n==0)
        {
            return 1;
        }
        
        if(n%2==0)
        {
            return helper(x*x, n/2);
        }
        else
        {
            return x*helper(x, n-1);
        }
        return 1;
        
    }
    
    
    double myPow(double x, long long int n) {
        
         double result=helper(x,abs(n));
        
        
        if(n>0)
            return result;
        else 
            return (1/result);
        
    }
};