class Solution {
public:
    int climbStairs(int n) {
            
            n = n + 2;
        
            int fib[n];
        
            fib[0]=0;
            fib[1]=1;

            for(int i=2;i<n;i++){
                fib[i] = fib[i-1] + fib[i-2];
            }
            
            return fib[n-1];
    }
};