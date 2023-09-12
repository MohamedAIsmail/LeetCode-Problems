class Solution
{
public:
    int minDeletions(string s)
    {
        map<char, int> mp;
        int deletions = 0;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        // Create a set to keep track of seen values
        std::unordered_set<int> seen_values;

        // Iterate over the map to check for repeated values and perform functionality
        for (const auto &entry : mp)
        {
            checkAgain:
            if (seen_values.count(entry.second) > 0 && entry.second != 0)
            {
                // If this value has been seen before, decrement it
                mp[entry.first]--;
                deletions++;
                goto checkAgain;
            }
            else
            {
                // Otherwise, add it to the set of seen values
                seen_values.insert(entry.second);
            }
        }

        return deletions;
    }
};