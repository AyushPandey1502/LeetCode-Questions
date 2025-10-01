class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int curr = numBottles;
        while(curr >= numExchange){
            result += curr / numExchange;
            numBottles = curr / numExchange;
            curr %= numExchange;
            curr += numBottles;
        }
        return result;
    }
};