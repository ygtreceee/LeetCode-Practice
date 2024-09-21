class Solution {
public:
    string getString(stack<string> stk){
        int len = stk.size();
        string ans = "";
        for(int i = 0; i < len; i++){
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }

    string reverseStack(stack<string> stk){
        stack<string> tmp;
        int len = stk.size();
        for(int i = 0; i < len; i++){
            tmp.push(stk.top());
            stk.pop();
        }
        return getString(tmp);
    }

    string decodeString(string s) {
        stack<string> stk;
        int index = 0;
        int len = s.length();
        char word;
        while(index < len){
            word = s[index];
            if(isdigit(word)){
                string digit = "";
                char tmp = s[index];
                while(tmp >= '0' && tmp <= '9'){
                    digit += tmp;
                    index++;
                    tmp = s[index];
                }
                stk.push(digit);
            }else if(isalpha(word) || word == '['){
                stk.push(string(1, word));
                index++;
            }else{
                index++;
                stack<string> repeatString;
                while(stk.top() != "["){
                    repeatString.push(stk.top());
                    stk.pop();
                }
                stk.pop();
                int loopTime = stoi(stk.top());
                stk.pop();
                string repeat = getString(repeatString);
                string tmp = "";
                while(loopTime--){
                    tmp += repeat;
                }
                stk.push(tmp);
            }
        }
        return reverseStack(stk);
    }
};