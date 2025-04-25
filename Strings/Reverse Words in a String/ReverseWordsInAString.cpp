class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";
        int i = 0;

        while(i < n){
            while(i < n && s[i] == ' '){
                i++;
            }
            if(i >= n){
                break;
            }
            string word = " ";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            if(temp != ""){
                temp += ' ';
            }
            temp += word;
        }

        s = temp;
        int left = 0, right = s.size() - 1;
        while(left < right){

        }
    }
};
