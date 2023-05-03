class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1, set2;
        vector<vector<int>> result = {{}, {}};

        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            set1.insert(nums1[i]);
        }
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            set2.insert(nums2[i]);
        }

        for (auto x : set1)
        {
            if (!set2.count(x))
                result[0].push_back(x);
        }

        for (auto x : set2)
        {
            if (!set1.count(x))
                result[1].push_back(x);
        }

        return result;
    }
};