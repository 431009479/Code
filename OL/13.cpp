/*************************************************************************
	> File Name: 13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 17时51分37秒
 ************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;

char str[55];
int arr[55];

int main(){
    for(int i = 0; i < 100; i++){
        scanf("%s", str);
        int len = strlen(str);
        if(arr[0] < len) arr[0] = len;
        for(int i = 0; i < len; i++){
            arr[len - i] += (str[i] - '0');
        }
        for(int k = 1; k <= arr[0]; k++){
            if(arr[k] < 10) continue;
            arr[k + 1] += arr[k] / 10;
            arr[k] %= 10;
            arr[0] += (arr[0] == k);
        }
    }

    for(int i = arr[0]; i > arr[0] - 10; i--){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
