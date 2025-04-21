class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows){
            return s;
        }
        vector<string> rows(numRows);
        int currRow = 0;
        int direction = 1;
        for (int i = 0; i < s.length(); i++) {
            rows[currRow] += s[i];
            if (currRow == 0){
                direction = 1;
            }
        }

    }
};
