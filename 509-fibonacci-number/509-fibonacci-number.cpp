class Solution
{
public:
    int fib(int n)
    {
        int fib1 = 0, fib2 = 0;

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        fib1 = fib1 + fib(n - 1);
        fib2 = fib2 + fib(n - 2);

        return fib1 + fib2;
    }
};