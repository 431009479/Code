/*************************************************************************
	> File Name: 素数筛.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月01日 星期一 22时49分28秒
 ************************************************************************/

#include<iostream>
#define N 1000
using namespace std;

int prime[N + 5];

void init_prime(){
    for(int i = 2; i < N; i++){
        if(prime[i]) continue;
        for(int j = i * i; j < N; j++){
            prime[j] = 1;
        }
    }
    return;
}


int main(){
    int n;
    init_prime();
    while(scanf("%d", &n) != EOF){
        printf("%s\n", prime[n] ? "NO": "YES");
    }


    return 0;
}
