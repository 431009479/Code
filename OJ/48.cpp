/*************************************************************************
	> File Name: 48.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月30日 星期四 18时48分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int n, sum = 0, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        sum += a;
    }
    cout << sum;
    return 0;
}
