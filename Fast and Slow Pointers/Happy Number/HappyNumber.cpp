class Solution {
public
    bool isHappy(int n){
    unordered_setint seen;

    while(n != 1 && seen.find(n) == seen.end()){
        seen.insert(n);
        int current = n;
        int sum = 0;

        while(current != 0){
            int digit = current % 10;
            sum += digit  digit;
            current = 10;
        }

        n = sum;
    }

    return n == 1;
}
};
