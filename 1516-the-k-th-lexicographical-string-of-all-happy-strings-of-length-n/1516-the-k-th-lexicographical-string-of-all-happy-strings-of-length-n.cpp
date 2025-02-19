class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n-1));
        if(total < k) return "";
        string result(n, 'a');
        unordered_map<char, char> nextSmallest = {
            {'a', 'b'}, {'b', 'a'}, {'c', 'a'}
        };
        unordered_map<char, char> nextGreatest = {
            {'a', 'c'}, {'b', 'c'}, {'c', 'b'}
        };

        int startA = 1;
        int startB = startA + (1 << (n-1));
        int startC = startB + (1 << (n-1));

        if(k < startB) k -= startA;
        else if(k < startC){
            result[0] = 'b';
            k -= startB;
        }else{
            result[0] = 'c';
            k -= startC;
        }

        for(int i = 1; i < n; i++){
            int mid = (1 << (n - i - 1));
            if(k < mid) result[i] = nextSmallest[result[i-1]];
            else{
                result[i] = nextGreatest[result[i-1]];
                k -= mid;
            }
        }
        return result;
    }
};