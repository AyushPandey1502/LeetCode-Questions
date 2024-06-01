class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0; i < 32; i++){
            int bitA = (a & (1 << i)) ? 1 : 0;
            int bitB = (b & (1 << i)) ? 1 : 0;
            int bitC = (c & (1 << i)) ? 1 : 0;
            if((bitA | bitB) != bitC){
                if(bitC == 0){
                    if(bitA == 1 && bitB == 1) count += 2;
                    else count += 1;
                }
                else count += 1;
            } 
        }
        return count;
    }
};