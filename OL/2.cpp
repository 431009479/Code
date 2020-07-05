/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 09时07分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max 4000000

int main(){
    int a = 1, b = 2;
    int sum = 2;
    while(a + b < max){
        b = a + b;
        a = b - a;
        if (!(b & 1)) sum += b;
    }

    cout << sum << endl;
    return 0;
}
