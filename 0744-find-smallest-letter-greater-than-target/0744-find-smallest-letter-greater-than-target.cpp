class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int targetValue = int(target);
        for (int i = 0; i < letters.size(); i++){
            if(int(letters[i]) > targetValue){
                return letters[i];
            }
        }

        return letters[0];
    }
};