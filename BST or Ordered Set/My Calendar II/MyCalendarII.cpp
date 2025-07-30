class MyCalendarTwo {
public:
    map<int, int> events;

    bool book(int start, int end) {
        events[start]++;
        events[end]--;

        int activeBookings = 0;
        for (const auto &[time, count] : events) {
            activeBookings += count;
            if (activeBookings > 2) {
                events[start]--;
                events[end]++;
                return false;
            }
        }
        return true;
    }
};
