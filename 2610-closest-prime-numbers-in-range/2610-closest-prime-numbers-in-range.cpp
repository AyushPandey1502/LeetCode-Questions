class Solution {
public:
    unordered_set<int> primes;
    void sieve(){
        vector<bool> is_prime(1e6+1, true);
        for(int i = 2; i * i <= 1e6; i++){
            if(is_prime[i]){
                for(int p = i*i; p <= 1e6; p+=i) is_prime[p] = false;
            }
        }
        for(int i = 2; i <= 1e6; i++){
            if(is_prime[i]) primes.insert(i);
        }
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> range;
        sieve();
        for(int i = left; i <= right; i++){
            if(primes.find(i) != primes.end()) range.push_back(i);
        }
        if(range.size() <= 1) return {-1, -1};
        int num1 = -1, num2 = -1, minDiff = INT_MAX;
        for(int i = 0; i < range.size()-1; i++){
            int diff = range[i+1] - range[i];
            if(diff < minDiff){
                minDiff = diff;
                num1 = range[i];
                num2 = range[i+1];
            }
        }
        return {num1, num2};
    }
};