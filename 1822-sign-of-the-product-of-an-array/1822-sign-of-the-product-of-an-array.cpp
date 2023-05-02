class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negativectr = 0;
        
        for(int i=0; i < nums.size(); i++){
            if(nums[i] < 0) negativectr++;
            if(nums[i] == 0) return 0;
        }
        
        if(negativectr % 2 == 0) return 1;
        else return -1;
    }
};