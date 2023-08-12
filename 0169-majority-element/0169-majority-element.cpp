class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // the majoirty will always be at the middle index

        int mid = nums.size()/2;
        return nums[mid];
    }
};