class AllOne {
public:
    unordered_map<string, int> map;
    set<pair<int, string>> set;

    AllOne() {
        map.clear();
        set.clear();
    }

    void inc(string key) {
        if (map.find(key) != map.end()) {
            set.erase({map[key], key});
        }
        map[key]++;
        set.insert({map[key], key});
    }

    void dec(string key) {
        set.erase({map[key], key});
        if (map[key] == 1) {
            map.erase(key);
        } else {
            map[key]--;
            set.insert({map[key], key});
        }
    }

    string getMaxKey() {
        if (!set.empty()) {
            return set.rbegin()->second;
        }
        return "";
    }

    string getMinKey() {
        if (!set.empty()) {
            return set.begin()->second;
        }
        return "";
    }
};