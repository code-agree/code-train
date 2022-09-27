class Solution {
public:
    string reverseWords(string s) {
        reverse_string(s);
        int left = 0, right = 0;
        while (right < s.length()){
            if (s[right] != ' '){
                ++right;
                continue;
            }
            else{
                string s_substr = s.substr(left,right - 1);
                reverse_string(s_substr);
                left = right + 1;
                ++right;
            }
        }
        return s;
    };
    void reverse_string(string& s){
        int i = 0, j = s.length() - 1;
        while(j > i){
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j; 
        }
    }
};