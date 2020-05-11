/*************************************************************************
	> File Name: 577_讲话模式.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 22时20分16秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;


void func(string &str){
    for(int i = 0; i <str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] =  char(str[i] + 32);

    }
}


int main(){
        
    map<string, int> mmap;
    string str, Str;
    int sum  = 0;
    while(cin >> str){
        func(str);
        mmap[str]++;
        if(mmap[str] > sum){
            Str = str;
            sum = mmap[str];
        }else if(mmap[str] == sum && Str > str){
            Str = str;
            sum = mmap[str];
        }
    }
    cout << Str <<" " << sum;
    return 0;
}
