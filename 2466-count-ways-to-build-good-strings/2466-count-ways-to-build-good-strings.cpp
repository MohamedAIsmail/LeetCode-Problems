class Solution {
public:
     int countGoodStrings(int low, int high, int zero, int one)
    {
        int count = 0;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= high; i++)
        {
            int val1 = 0, val2 = 0;

            if (i - zero >= 0)
            {
                val1 = dp[i - zero];
            }
            if (i - one >= 0)
            {
                val2 = dp[i - one];
            }
            dp[i] = (val1 + val2) % 1000000007;
            if (i >= low)
            {
                count = (count + dp[i]) % 1000000007;
            }
        }

        return count;
    }
};