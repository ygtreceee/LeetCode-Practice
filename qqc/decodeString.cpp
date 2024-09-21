// Source: https://leetcode.cn/problems/decode-string
// Author : ygtrece
// Date: 2024-09-21

# include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<pair<string, int>> stk;
    string res = "";
    int times = 0;
    for (auto c : s) {
        if (c == '[') {
            stk.emplace(res, times);   // save the last string and the mul times
            res = "";
            times = 0;
        }
        else if (c == ']') {           // operate immediately once meet with ']'
            auto [last_str, times] = stk.top();
            stk.pop();
            for (int j = 0; j < times; j++)
                last_str += res;
            res = last_str;
        }
        else if (isdigit(c)) {
            times = times * 10 + c - '0';
        }
        else res += c;
    }  
    return res;
}

int main()
{
    string encoded_string;
    cin >> encoded_string;
    string decoded_string = decodeString(encoded_string);
    cout << decoded_string;
    return 0;
}

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"