/*************************************************************************
	> File Name: 21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月15日 星期一 18时48分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 50

 

int isPrime[MAX_N + 5] = {0};
int prime[MAX_N] = {0};
int d[MAX_N + 5]  = {0};

 

int main() {
    d[1] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!isPrime[i]) { 
            isPrime[i] = i; //记录本身的值
            d[i] = i + 1; //记录因数和
            prime[++prime[0]] = i; //记录质数
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] *
                        (isPrime[i] * prime[j] * prime[j] - 1) / 
                      (isPrime[i] * prime[j] - 1);
                break;
            } else {
                isPrime[i * prime[j]] = prime[j];
                d[i * prime[j]] = d[prime[j]] * d[i];
            }
        }
    }
    for (int i = 0; i <= MAX_N; i++) {
        d[i] -= i;
    }

    int sum = 0;
    for (int i = 0; i <= MAX_N; i++) {
        if (d[i] <= MAX_N && d[i] != i && d[d[i]] == i) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
