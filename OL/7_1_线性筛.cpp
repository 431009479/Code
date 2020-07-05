/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 15时20分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 1000000


int arr[M + 5];
void frun(){
    for(int i = 2; i <= M; i++){
        if(!arr[i]) arr[++arr[0]] = i;
        for(int j = 1; j <= arr[0]; j++){
            if(arr[j] * i > M) break;
            arr[i * arr[j]] = 1;
            if(i % arr[j] == 0) break;
        }
    }
}

int main(){
    frun();
    cout << arr[10001] << endl;
    return 0;

}
