class Solution {
public:
    unordered_map<int, unordered_map<int, double>> memo;

    double serve(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (memo[A][B] > 0) return memo[A][B];

