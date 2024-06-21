class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int currUnsat = 0;
        for(int i = 0; i < minutes; i++){
            currUnsat += customers[i] * grumpy[i];
        }
        int i = 0;
        int j = minutes;
        int maxUnsatCustomers = currUnsat;
        while(j < n){
            currUnsat += customers[j] * grumpy[j];
            currUnsat -= customers[i] * grumpy[i];
            maxUnsatCustomers = max(maxUnsatCustomers, currUnsat);
            i++;
            j++;
        }
        int totalSat = maxUnsatCustomers;
        for(int i = 0; i < n; i++){
            totalSat += customers[i] * (1 - grumpy[i]);
        }
        return totalSat;
    }
};