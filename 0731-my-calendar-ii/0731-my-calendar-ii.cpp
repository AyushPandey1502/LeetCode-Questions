class MyCalendarTwo {
public:
    map<int, int> events;
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        
        int ongoingEvents = 0;
        for (auto [time, count] : events) {
            ongoingEvents += count;
            if (ongoingEvents >= 3) {
                events[start]--;
                events[end]++;
                return false;
            }
        }
        return true;
    }
};

