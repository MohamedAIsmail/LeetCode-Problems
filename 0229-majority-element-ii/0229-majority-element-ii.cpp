class Solution {
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result;

        map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            if (map[nums[i]])
            {
                map[nums[i]]++;
            }
            else
            {
                map[nums[i]] = 1;
            }
        }

        for(auto item : map){
            if(item.second > n / 3){
                result.push_back(item.first);
            }
        }
        
        return result;
    }
};