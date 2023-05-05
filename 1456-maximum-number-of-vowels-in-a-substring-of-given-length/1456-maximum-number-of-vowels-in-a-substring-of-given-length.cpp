class Solution {
public:
    int maxVowels(string s, int k)
    {
        unordered_map<int, int> map;
        int maxVow = 0;
        int VowCtr = 0;

        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                VowCtr++;
            }
        }
        maxVow = VowCtr;
        for (int i = k; i < s.size(); i++)
        {
            int j = i - k;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                VowCtr++;
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u')
                VowCtr--;

            maxVow = max(maxVow, VowCtr);
        }
        return maxVow;
    }
};