class Solution {
public:
    unordered_map<int, unordered_map<int, double>> memo;

    double serve(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (memo[A][B] > 0) return memo[A][B];

        memo[A][B] = 0.25 * (serve(A - 100, B) +
                             serve(A - 75, B - 25) +
                             serve(A - 50, B - 50) +
                             serve(A - 25, B - 75));

        return memo[A][B];
    }

