/*************************************************************************
	> File Name: 260.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 11时36分09秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack <char> sta;



void clear(){
    while(!sta.empty()){
        sta.pop();
    }
}
int main(){
    string s;
    cin >> s;
    int ans = 0, t = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            sta.push(s[i]);
        }else if(s[i] == ')'){
            if(sta.empty() || sta.top() != '('){
                ans = max(ans, t);
                t = 0;
                clear();
            }else if(sta.top() == '('){
                t += 2;
                sta.pop();
                ans = max(ans, t);
                
            }
        }else if(s[i] == ']'){
            if(sta.empty() || sta.top() != '['){
                ans = max(ans, t);
                t = 0;
                clear();
            }else if(sta.top() == '['){
                t += 2;
                sta.pop();
                ans = max(ans, t);
                
            }
        }else if(s[i] == '}'){
            if(sta.empty() || sta.top() != '{'){
                ans = max(ans, t);
                t = 0;
                clear();
            }else if(sta.top() == '{'){
                t += 2;
                sta.pop();
                ans = max(ans, t);
                
            }
        }
    }
    ans = max(ans, t);
    cout << ans;
    return 0;
}
