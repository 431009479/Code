/*************************************************************************
	> File Name: 47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 21时45分50秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 1000000

int arr[MAX + 5];

void func(){
    for(int i = 2; i < MAX; i++){
        if(arr[i]) continue;
        for(int j = i; j < MAX; j += i){
            arr[j] += 1;
    }       
    
}
}

int main(){
    func();
    for(int i = 2; i < MAX; i++){
        int  flag = 1;
        for(int j = 0; j < 4 && flag; j++){
            flag = (arr[i + j] == 4);
        }
        if(flag){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
