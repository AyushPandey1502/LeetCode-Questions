class NumberContainers {
public:
    unordered_map<int, int> index;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;

    NumberContainers() {}

    void change(int ind, int number) {
        if (index.count(ind)) {
            int num = index[ind];
            if (num == number) return;
        }
        index[ind] = number;
        map[number].push(ind);
    }

    int find(int number) {
        if (map.count(number) == 0) return -1;
        while (!map[number].empty()) {
            int ind = map[number].top();
            if (index[ind] == number) return ind;
            map[number].pop();
        }
        return -1;
    }
};