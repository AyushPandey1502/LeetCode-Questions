class MyCalendar {
public:
    set<pair<int, int>> events;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (auto it : events) {
            if (max(it.first, start) < min(it.second, end)) {
                return false; 
            }
        }
        events.insert({start, end});  
        return true;
    }
};


