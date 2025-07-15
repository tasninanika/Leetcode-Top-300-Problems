class Solution {
public:
    bool canFinish(vector<int>& piles, int speed, int h) {
        int totalHours = 0;
        for (int bananas : piles) {
            totalHours += ceil((double)bananas / speed);
            if (totalHours > h) return false;
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFinish(piles, mid, h)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
