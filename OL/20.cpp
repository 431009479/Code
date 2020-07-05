/*************************************************************************
	> File Name: 20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 20时34分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 500

int arr[MAX] ={ 1, 1, 0 };

int main(){
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= arr[0]; j++){
            arr[j] *= i;
        }
        for(int k = 1; k <= arr[0]; k++){
            if(arr[k] < 10) continue;
            arr[k + 1] += arr[k] / 10;
            arr[k] %= 10;
            arr[0] +=(arr[0] == k);
        }
    }
    int sum = 0;
    for(int i = arr[0]; i > 0; i--){
        sum += arr[i];
    }
    cout << sum << endl;
    return 0;
}
