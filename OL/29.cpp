/*************************************************************************
	> File Name: 29.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月13日 星期六 11时46分28秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define MAX 10000
#define N 210

int arr[MAX + 5][N];
int len = 0;

int find(int *temp){
    for(int i = 0; i < len; i++){
        if(memcmp(arr + i, temp, sizeof(int) * N) == 0){
            return i + 1;
        }
    }
    return 0;
}



int main(){
    for(int i  = 2; i <= 100; i++){
        for(int j = 2; j <= 100; j++){
            int temp[N] = {1, 1, 0};
            for(int k = 0; k < j; k++){
                for(int p = 1; p <= temp[0]; p++){
                    temp[p] *= i;
                }
                for(int t = 1; t <= temp[0]; t++){
                    if(temp[t] < 10) continue;
                    temp[t + 1] += temp[t] / 10;
                    temp[t] = temp[t] % 10;
                    temp[0] += (temp[0] == t);
                }
            }
            if(find(temp) == 0){
                memcpy(arr + len, temp, sizeof(int) * N);
                len++;
            }
        }
    }
    cout << len << endl;
    return 0;
}
