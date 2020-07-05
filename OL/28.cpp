/*************************************************************************
	> File Name: 28.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 10时36分14秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 1001
int len = 2;
int sum = 1;
int main(){
    while (len <= M / 2 + 1){
        int m = (len * 2 - 1);
        sum += 4 * m * m - 6 * m + 6;
        len += 1;
    }
    cout << sum;
    return 0;
}
