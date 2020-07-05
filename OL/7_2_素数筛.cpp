/*************************************************************************
	> File Name: 7_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 15时25分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 200000


int arr[M + 5];
int k = 0;
void func(){
    for(int i = 2; i <  M; i++){
        if(arr[i]) continue;
        arr[++arr[0]] = i;
        for(int j = i; j < M; j += i){
            arr[j] = 1;
        }
    }
    return ;
}


int main(){
    func();
    cout << arr[10001] << endl;
    return 0;
}
