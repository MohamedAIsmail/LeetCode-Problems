class Solution
{
public:
    int longestPalindrome(string s)
    {
        int longestPali = 0;
        int ctr = 0;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            if (map.count(s[i]))
            {
                map[s[i]]++;
            }
            else
            {
                map[s[i]] = 1;
            }
        }

        for (auto &it : map)
        {
            longestPali = longestPali + (it.second / 2 * 2);
            if (longestPali % 2 == 0 && it.second % 2 == 1)
            {
                longestPali++;
            }
        }

        return longestPali;
    }
};