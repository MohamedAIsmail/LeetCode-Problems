class Solution {
public:
    int maxVowels(string s, int k)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxVow = 0;
        int VowCtr = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i >= k && vowels.count(s[i - k]))
            {
                VowCtr--;
            }
            if (vowels.count(s[i]))
            {
                VowCtr++;
            }
            maxVow = max(maxVow, VowCtr);
        }

        return maxVow;
    }
};