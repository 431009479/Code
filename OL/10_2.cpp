/*************************************************************************
	> File Name: 10_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 17时28分04秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 2000000
int arr[M + 5];
long long sum;

void func(){
    for(int i = 2; i <= M; i++){
        if(arr[i]) continue;
        sum += i;
        for(int j = 2 * i; j <= M; j += i){
            arr[j] = 1;
        }
    }
    cout << sum << endl;
}

int main(){
    func();
    return 0;
}
