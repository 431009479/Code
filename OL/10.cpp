/*************************************************************************
	> File Name: 10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 17时17分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 2000000
int arr[2000005];

long long sum;

void func(){
    for(int i = 2; i <= M; i++){
        if(!arr[i]){
            sum += i;
            arr[++arr[0]] = i;
        }
        for(int j = 1; j <= arr[0]; j++){
            if(arr[j] * i > M) break;
            arr[i * arr[j]] = 1;
            if(i % arr[j] == 0) break;
        }
    }


    cout << sum << endl;
}


int main(){
    func();
    return 0;
}
