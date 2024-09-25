#include<iostream>
#include<string>
using namespace std;
string solution(string in) {
    string res,sav;
    int repeat = 0;
    int leftcount = 0;
    int rightcount = 0;
    for(int i = 0; i < in.length(); i++) {
        if(in[i] >= '0' && in[i] <= '9') {
            sav = "";
            rightcount = 0;
            leftcount = 0;
            while(in[i] != '['){
                repeat *= 10;
                repeat += (int)(in[i]) - 48;
                i++;
            }

            for(int j = i; j < in.length(); j++) {
                if(in[j] == '['){
                    leftcount++;
                }else if(in[j] == ']'){
                    rightcount++;
                }

                if(leftcount != 0 && rightcount != 0 && leftcount == rightcount) {
                    for(int i1 = i+1; i1 < j; i1++) {
                        sav += in[i1];
                    }
                    i = j;
                    break;
                }
            }
            if(rightcount != 1){
                for(int i1 = 0; i1 < repeat; i1++) {
                    res.append(solution(sav));
                }
                repeat = 0;
            }else{
                for(int i1 = 0; i1 < repeat; i1++) {
                    res.append(sav);
                }
                repeat = 0;
            }

        }else{
            res += in[i];
        }
    }
    return res;
}   




int main(){
    string a;
    cin>>a;
    cout<<solution(a)<<endl;
}
