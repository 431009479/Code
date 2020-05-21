/*************************************************************************
	> File Name: 565_位的交换.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月18日 星期一 22时13分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, ans;

int main(){
    cin >> n;
    ans = ((n >> 16) & 0x0000ffff) | ((n << 16) & 0xffff0000);
    cout << ans;
    return 0;
}
