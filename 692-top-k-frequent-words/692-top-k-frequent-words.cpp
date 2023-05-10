class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> freq;
        vector<string> ans;

        for (auto &word : words)
        {
            freq[word]++;
        }

        vector<pair<string, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             {
            if (a.second == b.second)
                return (a.first < b.first);
            return a.second > b.second; });

        for (pair p : vec)
        {
            ans.push_back(p.first);
            if (--k == 0)
                break;
        }

        return ans;
    }
};