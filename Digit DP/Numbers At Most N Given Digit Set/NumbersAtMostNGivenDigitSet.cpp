class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string NS = to_string(N);
        int K = NS.size();
        int dp[K + 1];
        dp[K] = 1;

        for (int i = K - 1; i >= 0; --i) {
            int Si = NS[i] - '0';
            dp[i] = 0;

            for (auto &d : D) {
                if (d[0] - '0' < Si) {
                    dp[i] += pow(D.size(), K - i - 1);
                } else if (d[0] - '0' == Si) {
                    dp[i] += dp[i + 1];
                }
            }
        }

        int answer = 0;
        for (int i = 1; i < K; ++i) {
            answer += pow(D.size(), i);
        }

        return answer + dp[0];
    }
};
