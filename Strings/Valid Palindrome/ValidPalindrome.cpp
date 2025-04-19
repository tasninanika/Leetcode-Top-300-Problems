class Solution {
public:
    bool isPalindrome(string s) {
        string temp_string = "";

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                temp_string += tolower(s[i]);
            }
        }

        int i = 0, j = temp_string.size() - 1;
        while(i < j){
            if(temp_string[i] != temp_string[j]){
                return false;
            }

    }
};

