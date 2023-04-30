class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int max = 0, result = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            max = max + gain[i];
            if(max > result){
                result = max;
            }
        }

        return result;
    }
};