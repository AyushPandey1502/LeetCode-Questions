class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int it : asteroids) {
            while (!result.empty() && result.back() > 0 && it < 0) {
                if (result.back() < -it) {
                    result.pop_back();
                    continue;
                }
                if (result.back() == -it) result.pop_back();
                it = 0;
                break;
            }
            if (it != 0) result.push_back(it);
        }
        return result;
    }
};
