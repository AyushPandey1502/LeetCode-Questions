class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0, minPenalty = INT_MAX, result = 0;
        int suffixY = 0;
        for(char c : customers) {
            if(c == 'Y') suffixY++;
        }
        minPenalty = suffixY;
        int openNoCustomer = 0;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'N') openNoCustomer++;
            else suffixY--; 
            int totalPenalty = openNoCustomer + suffixY;
            if(totalPenalty < minPenalty){
                minPenalty = totalPenalty;
                result = i + 1; 
            }
        }
        return result;
    }
};
