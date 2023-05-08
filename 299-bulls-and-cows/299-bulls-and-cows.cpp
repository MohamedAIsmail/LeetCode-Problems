class Solution {
public:
    string getHint(string secret, string guess)
    {
        unordered_map<int, int> map;
        int bullCtr = 0, cowsCtr = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bullCtr++;
                map[i]++;
            }
            else
            {
                map[secret[i] + 1000]++;
            }
        }

        for (int i = 0; i < secret.size(); i++)
        {
            if (map[guess[i] + 1000] && map[i] < 1)
            {
                cowsCtr++;
                map[guess[i] + 1000]--;
            }
        }

        return (to_string(bullCtr) + 'A' + to_string(cowsCtr) + 'B');
    }
};