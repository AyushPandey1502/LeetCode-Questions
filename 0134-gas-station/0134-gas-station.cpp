class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sumGas = accumulate(gas.begin(), gas.end(), 0);
        int sumCost = accumulate(cost.begin(), cost.end(), 0);
        if(sumCost > sumGas) return -1; 

        int currGas = 0;
        int index = 0;
        for(int i = 0; i < n; i++){
            currGas += gas[i] - cost[i];
            if(currGas < 0){
                currGas = 0;
                index = i + 1;
            }
        }
        return index;
    }
};