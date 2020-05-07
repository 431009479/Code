/*************************************************************************
	> File Name: 543_分书问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 16时24分32秒
 ************************************************************************/

#include<iostream>
using namespace std;


int n, check[25], sum = 0;
char arr[25][25];

void func(int i){
    if(i == n + 1)
        sum++;
    for(int j = 1; j <= n; j++){
        if(arr[i][j] == '1' && check[j] == 0){
            check[j] = 1;
            func(i + 1);
            check[j] = 0;
        }
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    func(1);
    cout << sum;
    return 0;
}
