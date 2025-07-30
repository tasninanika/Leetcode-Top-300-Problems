class MyCalendar {
private:
    std::map<int, int> events;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto next_event = events.lower_bound(start);

        if (next_event != events.end() && next_event->first < end) {
            return false;
        }

        if (next_event != events.begin()) {
            auto prev_event = std::prev(next_event);
            if (prev_event->second > start) {
                return false;
            }
        }

        events[start] = end;
        return true;
    }
};
