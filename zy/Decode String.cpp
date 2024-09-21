class Solution {
public:
    string decodeString(string s, int &i) {
        string ans;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < s.size() && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string decodedString = decodeString(s, i);
                i++;
                while (k--) {
                    ans += decodedString;
                }
            } else {
                ans += s[i++];
            }
        }
        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};