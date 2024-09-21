class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        string ans = "";
        for(char x : s){
            if(x != ']'){
                stack.push(x);
            }else{
                string str = "";
                while(!stack.empty() && isalpha(stack.top())){
                    str = stack.top() + str;
                    stack.pop();
                }
                stack.pop();

                string numberstr = "";
                while(!stack.empty() && isdigit(stack.top())){
                    numberstr = stack.top() + numberstr;
                    stack.pop();
                }
                int count = stoi(numberstr);

                while(count){
                    for(char ch : str){
                        stack.push(ch);
                    }
                    count--;
                }
            }
        }
        while(!stack.empty()){
            ans = stack.top() + ans;
            stack.pop();
        }
        return ans;
    }
};