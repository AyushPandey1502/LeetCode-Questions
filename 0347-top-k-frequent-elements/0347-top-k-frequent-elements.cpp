class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::unordered_map<int, int> frequency_map;
        for (int num : nums) {
            frequency_map[num]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;

        for (const auto& pair : frequency_map) {
            min_heap.push({pair.second, pair.first});
            if (min_heap.size() > k) {
                min_heap.pop(); 
            }
        }
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return result;
    }
};
