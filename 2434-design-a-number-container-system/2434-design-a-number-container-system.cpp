class NumberContainers {
public:
    unordered_map<int, int> index;
    unordered_map<int, set<int>> mp;

    NumberContainers() {}
    
    void change(int idx, int number) {
        if(index.count(idx)){
            int num = index[idx];
            mp[num].erase(idx);
        }
        mp[number].insert(idx);
        index[idx] = number;
    }
    
    int find(int number) {
        if(mp.count(number) && !mp[number].empty()) return *mp[number].begin();
        return -1;
    }
};
