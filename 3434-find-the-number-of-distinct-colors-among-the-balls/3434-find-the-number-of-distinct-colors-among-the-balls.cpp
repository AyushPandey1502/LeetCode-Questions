class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> freq, balls;
        
        for(auto q : queries) {
            int ball = q[0], color = q[1];
            
            if(balls.count(ball)) {
                int prevColor = balls[ball];
                if(--freq[prevColor] == 0) freq.erase(prevColor);
            }
            balls[ball] = color;
            freq[color]++;
            result.push_back(freq.size());
        }
        return result;
    }
};
