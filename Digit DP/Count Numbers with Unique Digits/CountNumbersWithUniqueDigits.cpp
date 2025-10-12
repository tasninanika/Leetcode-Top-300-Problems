class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        int result = 10;
        int unique_digit_count = 9;
        int available_digits = 9;
