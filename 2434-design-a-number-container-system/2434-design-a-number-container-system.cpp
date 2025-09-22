class NumberContainers {
public:
    unordered_map<int, int> index; 
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

    NumberContainers() {}

    void change(int idx, int number) {
        index[idx] = number;
        mp[number].push(idx); 
    }

    int find(int number) {
        if (!mp.count(number)) return -1;
        auto &pq = mp[number];
        while (!pq.empty() && index[pq.top()] != number) pq.pop();
        return pq.empty() ? -1 : pq.top();
    }
};
