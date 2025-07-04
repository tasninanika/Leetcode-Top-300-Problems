class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge_map;
        stack<int> s;

        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                nge_map[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(nge_map.count(num) ? nge_map[num] : -1);
        }

        return result;
    }
};

