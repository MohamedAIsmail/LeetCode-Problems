class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        
        loop:
        while(num > 0){
            sum = sum + (num % 10);
            num = num / 10;
        }
        
        if(sum / 10 != 0){
            num = sum;
            sum = 0;
            goto loop;
        }
        else{
            return sum;
        }
        
        return sum;
    }
};