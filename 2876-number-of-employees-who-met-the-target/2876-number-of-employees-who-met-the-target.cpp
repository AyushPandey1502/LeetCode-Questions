class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for(int hr: hours){
            if(hr >= target) count++;
        }
        return count;
    }
};