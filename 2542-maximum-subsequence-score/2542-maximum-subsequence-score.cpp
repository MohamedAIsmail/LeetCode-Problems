class Solution {
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
            vec.push_back({nums2[i], i});

        sort(vec.rbegin(), vec.rend());

        long long res = 0, currSum = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < vec.size(); i++)
        {
            auto &[a, b] = vec[i];
            currSum += nums1[b];
            pq.push(nums1[b]);

            if(pq.size() == k)
                res = max(res, currSum * a);
            
            if(pq.size() > k-1){
                currSum -= pq.top();
                pq.pop();
            }
        }

        return res;
    }
};