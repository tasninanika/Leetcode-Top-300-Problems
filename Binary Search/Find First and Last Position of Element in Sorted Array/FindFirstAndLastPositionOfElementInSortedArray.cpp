class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirstPosition(nums, target), findLastPosition(nums, target)};
    }

    int findFirstPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int firstPosition = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                firstPosition = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return firstPosition;
    }

    int findLastPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int lastPosition = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                lastPosition = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return lastPosition;
    }
};
