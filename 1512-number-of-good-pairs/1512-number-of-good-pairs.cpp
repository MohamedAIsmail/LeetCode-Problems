class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(map.count(nums[i]))
            {
                result += map[nums[i]];
                map[nums[i]]++;
            }
            else
            {
                map[nums[i]] = 1;
            }
        }

        return result;
    }
};