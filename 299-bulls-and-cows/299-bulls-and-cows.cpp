class Solution {
public:
    string getHint(string secret, string guess)
    {
        unordered_map<int, int> map;
        int bullCtr = 0, cowsCtr = 0;
        vector<int> secretCtr(10, 0);

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bullCtr++;
                guess.erase(i, 1);
                secret.erase(i, 1);
                i--;
            }
            else
            {
                map[secret[i]]++;
            }
        }

        for (int i = 0; i < secret.size(); i++)
        {
            if (map[guess[i]])
            {
                cowsCtr++;
                map[guess[i]]--;
            }
        }

        return (to_string(bullCtr) + 'A' + to_string(cowsCtr) + 'B');
    }
};