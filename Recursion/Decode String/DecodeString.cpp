class Solution {
public:
    string decodeStringHelper(const string &s, int &i) {
        string result;

        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) {
                result += s[i++];
            }
            else {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string decodedStr = decodeStringHelper(s, i);
                while (num-- > 0){
                    result += decodedStr;
                }
                i++;
            }
        }
        return result;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeStringHelper(s, i);
    }
};
