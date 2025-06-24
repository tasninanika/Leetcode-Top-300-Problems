class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) {
        unordered_map<int, int> remainderMap;
        remainderMap[0] = 1;
        int cumulativeSum = 0;
        int c = 0;

        for(int num : nums){
            cumulativeSum += num;
            int remainder = ((cumulativeSum % K) + K) % K;

            if(remainderMap.find(remainder) != remainderMap.end()){
                c += remainderMap[remainder];
            }

            ++remainderMap[remainder];
        }

        return c;
    }
};
