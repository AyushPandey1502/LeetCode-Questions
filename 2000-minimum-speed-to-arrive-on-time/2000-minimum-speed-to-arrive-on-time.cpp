class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size(), result = -1;
        int left = 1, right = 1e9;

        auto check = [&](int mid){
            double time = 0;
            for(int i = 0; i < n; i++){
                if(i < n-1) time += (dist[i] + mid -1) / mid;
                else time += (double)dist[i] / mid;
                if(time > hour) return false;
            }
            return time <= hour;
        };

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid)){
                result = mid;
                right = mid - 1;
            }else left = mid + 1;
        }
        return result;
    }
};