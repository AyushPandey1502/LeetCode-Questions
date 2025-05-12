class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> result;
        int n = digits.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && j != k && i != k) {
                        int a = digits[i], b = digits[j], c = digits[k];
                        if (a == 0) continue;  
                        if (c % 2 != 0) continue; 
                        int num = a * 100 + b * 10 + c;
                        result.insert(num);
                    }
                }
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
