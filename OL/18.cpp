/*************************************************************************
	> File Name: 18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 20时25分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
int arr[20][20];


int main(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 13; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            arr[i][j] += max(arr[i + 1][j + 1], arr[i + 1][j]);
        }
    }

    cout << arr[0][0] << endl;
    return 0;
}
