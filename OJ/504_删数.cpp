/*************************************************************************
	> File Name: 504_删数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 18时04分01秒
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int n; 
int s;
string str;

int main(){
    cin >> str >> n;
    for(int i = n; i > 0; i--){
        int ind = str.size() - 1;
        for(int j = 0; j < str.size() - 1; j++){
            if(str[j] > str[j + 1]){
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }
    int f = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != '0') f = 1;
        if(f == 1) cout << str[i];
    }
    return 0;
}
