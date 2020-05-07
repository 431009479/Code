/*************************************************************************
	> File Name: 592_六十四进制.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 20时50分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

int num[64], num2[10] = {1, 2, 4, 8, 16, 32};
long long ans = 1;
char str[100005];

int main(){
    cin >> str;
    for(int i = 0; i < 64; i++){
        int t = i;
        for(int j = 5;  j >= 0; j--){
            if(t >= num2[j]){
                num[i]++;
                t -= num2[j];
            }
        }
    }
    for(int i = 0; str[i]; i++){
        int t;
        if(str[i] >= '0' && str[i] <='9'){
            t = str[i] -'0';
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            t = str[i] - 'A' + 10;
        }else if(str[i] >= 'a' && str[i] <= 'z'){
            t = str[i] - 'a' + 36;
        }else if(str[i] == '-'){
            t = 62;
        }else{
            t = 63;
        }
        t = 6 - num[t];
        for(int i = 0; i < t; i++){
            ans = ans * 3 % 1000000007;
        }
    }
    cout << ans<< endl;
    return 0;
}
