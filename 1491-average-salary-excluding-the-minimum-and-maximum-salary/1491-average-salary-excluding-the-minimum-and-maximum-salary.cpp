class Solution {
public:
    double average(vector<int>& salary) {
        
       int minSalary =  *min_element(salary.begin(), salary.end());
        int maxSalary = *max_element(salary.begin(), salary.end());
        
        double sum = 0;
        
        for(int i=0; i < salary.size(); i++){
            if(salary[i] == minSalary || salary[i] == maxSalary){
                continue;
            }
            else{
                sum = sum + salary[i];
            }
        }
        
        return (double)sum/ (salary.size()-2);
    }
};