/*************************************************************************
	> File Name: 591_游戏.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 20时30分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m;

int main(){
    cin >> n >> m;
    double f = n / 2.0;
    if(f > m) cout << m + 1;
    if(f <= m) cout << m - 1;
    

    return 0;
}
