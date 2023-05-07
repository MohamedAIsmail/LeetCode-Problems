class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> vec(obstacles.size()+1, INT_MAX), ans;

        for(auto it : obstacles)   {
            int ind = upper_bound(vec.begin(), vec.end(), it) - vec.begin();
            vec[ind] = it;
            ans.push_back(ind+1);
        }

        return ans; 
    }
};