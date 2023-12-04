class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
        {
            return result;
        }

        const vector<string> digitToLetters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        result.push_back("");

        for (char digit : digits)
        {
            int digitIndex = digit - '2';
            if (digitIndex < 0 || digitIndex >= digitToLetters.size())
            {
                // Handle invalid digits
                return result;
            }

            const string &letters = digitToLetters[digitIndex];

            vector<string> temp;

            for (char letter : letters)
            {
                for (const string &prevCombination : result)
                {
                    temp.push_back(prevCombination + letter);
                }
            }

            result = temp;
        }
        return result;
    }
};