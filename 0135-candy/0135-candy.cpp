class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1); // Initialize a vector to store the number of candies for each child

        // Check ratings from left to right
        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i] && candies[i - 1] >= candies[i])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Check ratings from right to left
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i + 1] < ratings[i] && candies[i + 1] >= candies[i])
            {
                candies[i] = candies[i + 1] + 1;
            }
        }

        int candyNum = 0;
        for(auto i: candies){
            candyNum += i;
        }
        return candyNum;
    }
};