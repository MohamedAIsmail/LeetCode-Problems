class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int rows = 1; rows <= m; rows++)
            dp[rows][0] = rows;

        for (int columns = 1; columns <= n; columns++)
            dp[0][columns] = columns;

        for (int rows = 1; rows <= m; rows++)
        {
            for (int columns = 1; columns <= n; columns++)
            {
                if (word1[rows - 1] == word2[columns - 1])
                    dp[rows][columns] = dp[rows - 1][columns - 1];
                else
                    dp[rows][columns] = min({dp[rows - 1][columns - 1], dp[rows - 1][columns], dp[rows][columns - 1]}) + 1;
            }
        }

        return dp[m][n];
    }
};