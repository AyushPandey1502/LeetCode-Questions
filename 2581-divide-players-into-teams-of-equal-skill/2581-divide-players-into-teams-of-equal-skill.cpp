class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long totalSum = accumulate(skill.begin(), skill.end(), 0);
        long long sum = totalSum / (n / 2);
        sort(skill.begin(), skill.end());
        
        long long result = 0;
        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n - i - 1] != sum) return -1;
            result += (long long)skill[i] * skill[n - i - 1];
        }
        return result;
    }
};
