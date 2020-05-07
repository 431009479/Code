/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月18日 星期二 14时24分13秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<math.h>
#define max_n 100
#include<inttypes.h>

int cala(const char *str, int l, int r){
    int prior = 0x3f3f3f3f - 1, tmep = 0, pos = -1;
    for(int i = l ; i <= r; i++){
        int cur_prior = 0x3f3f3f3f;
        switch(str[i]){
            case '(':tmep += 100;break;
            case ')':tmep -= 100;break;
            case '+':
            case '-':cur_prior = tmep += 1; break;
            case '*':
            case '/':cur_prior = tmep += 2; break;
            case '^':cur_prior = tmep += 3; break;
        }
        if(cur_prior <= prior){
            prior = cur_prior;
            pos = i;
        }
    }
    if(pos == -1){
        int num = 0;
        for(int i = l; i <= r; i++){
        if(str[i] < '0' || str[i] >'9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    }
    int a = cala(str, l, pos - 1);
    int b = cala(str, pos + 1, r);
    switch(str[pos]){
        case '+' :return a + b;
        case '-' :return a - b;
        case '*' :return a * b;
        case '/' :return a / b;
        case '^' :(int)pow(a, b);
    }
    return 0;
}


int main(){
 char str[max_n + 5] = {0};
    while(~scanf("%[^\n]s", str)){
        getchar();
        printf("%d\n",cala(str, 0, strlen(str) - 1));
    }
    return 0;
}
