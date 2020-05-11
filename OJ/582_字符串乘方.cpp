/*************************************************************************
	> File Name: 582_字符串乘方.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 21时41分37秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string str;
string s = ".";
int ans = 1, sum = 1, k, flag = 1;

void func(){
    for(int i = 1; i < str.size(); i++){
        if(flag && str[i] == str[i - ans]){
            k++;
            if(k == ans){
                sum++;
                ans++;
                flag = 0;
            }
        }else{
            if(flag == 0 &&str.substr(0, k) == str.substr(i, k)){
                sum++;
            }else{
                ans++;
            }
        }
    }
}



int main(){
    while(cin >> str){
        if(str == s) return 0 ;
        func();
        cout << sum <<'\n';
        sum = 1;
    }
     return 0;
}
