class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> res;
        int maxElement = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > maxElement)
            {
                maxElement = candies[i];
            }
        }

        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= maxElement)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};