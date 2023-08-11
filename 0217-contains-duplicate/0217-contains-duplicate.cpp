class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > 1){
                return true;
            }
        }
        return false;
            
    }
};