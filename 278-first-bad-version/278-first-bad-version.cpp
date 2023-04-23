// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        long int start = 0;
        long int end = n;
        long int result = 0;
        
        while(start <= end){
            
            long int mid = (end + start)/2;
            
            if(isBadVersion(mid)){
                result = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return result;
    }
};