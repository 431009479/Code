/*************************************************************************
	> File Name: 583_字符串处理.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 21时15分55秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;


string str;
int ans = 0;

void func1(int l, int r){
    for(int i =0; i <= l; i++){
        if( str[l - i] != str[r + i]){
            break;
        }
        ans++;
    }
    return ;
}

void func(){
    for(int i = 0; i < str.size(); i++){
        func1(i, i);
        func1(i, i + 1);
        
    }
    return ;
}


int main(){

    while(cin >> str){
        func();
        cout << ans << endl;
        ans = 0;
    }
    
    return 0;
}
