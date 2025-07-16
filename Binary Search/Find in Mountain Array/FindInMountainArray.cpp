class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }

        int peak = left;

        int index = binarySearch(mountainArr, target, 0, peak, true);
        if (index != -1) {
            return index;
        }

        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }

    int binarySearch(MountainArray &arr, int target, int low, int high, bool ascending) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midValue = arr.get(mid);
            if (midValue == target) {
                return mid;
            }

            if (ascending) {
                if (midValue < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (midValue < target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
