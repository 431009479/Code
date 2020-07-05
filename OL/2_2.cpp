/*************************************************************************
	> File Name: 2_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 09时13分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max 4000000

int arr[3] = {0, 1};
int main(){
    int n = 1;
    int sum = 0;
    while(arr[n % 3] + arr[(n - 1) % 3] < max){
        n++;
        arr[n % 3] = arr[(n - 1) % 3] + arr[(n -2) % 3];
        if(!(arr[n % 3] & 1)) sum += arr[n % 3];
    }
    cout << sum;
    return 0;
}
