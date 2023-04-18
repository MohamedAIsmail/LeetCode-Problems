class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string mergedString = "";
        int i = 0, j = 0;

        while (i < word1.size() && j < word2.size())
        {
            mergedString = mergedString + word1[i++] + word2[j++];
        }

        // Remaining characters are appended after the loop finishes
        mergedString += word1.substr(i);
        mergedString += word2.substr(j);

        return mergedString;
    }
};