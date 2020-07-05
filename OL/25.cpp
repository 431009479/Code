/*************************************************************************
	> File Name: 25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 21时21分41秒
 ************************************************************************/

#include<iostream>
using namespace std;
int arr[3][1005];

int main(){
    int n = 2;
    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[2][0] = 1;
    arr[2][1] = 1;
    while(arr[n % 3][0] < 1000){
        n++;
        int *a = arr[n % 3], *b = arr[(n - 1) % 3], *c = arr[(n - 2) % 3];
        for(int i = 1; i <= b[0]; i++){
            a[i] = b[i] + c[i]; 
        }
        a[0] = b[0];
        for(int i = 1; i <= a[0]; i++){
            if(a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (i == a[0]);
        }
    }
    cout << n; 
    return 0;
}
