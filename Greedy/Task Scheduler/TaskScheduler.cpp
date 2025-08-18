class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int max_count = *std::max_element(freq.begin(), freq.end());
        int num_max_tasks = std::count(freq.begin(), freq.end(), max_count);

        int min_length = (max_count - 1) * (n + 1) + num_max_tasks;

        return std::max(min_length, static_cast<int>(tasks.size()));
    }
};
