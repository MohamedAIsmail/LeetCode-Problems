class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]) == 0)
            {
                map[nums[i]] = 1;
            }
            else
            {
                map[nums[i]]++;
            }
        }
        priority_queue<pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            pq.push(make_pair(it->second, it->first));
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};