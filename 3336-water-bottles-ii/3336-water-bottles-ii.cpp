class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0;
        int emptyBottles = 0;

        while(numBottles > 0){
            count += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
            
            if(emptyBottles >= numExchange){
                numBottles += 1;
                emptyBottles -= numExchange;
                numExchange++;
            }
        }
        return count;
    }
};
