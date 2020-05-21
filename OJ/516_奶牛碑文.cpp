/*************************************************************************
	> File Name: 516_奶牛碑文.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月18日 星期一 21时39分43秒
 ************************************************************************/

#include<iostream>
using namespace std;


long long n, sum = 0;
long long ans[100005];
long long num[100005];
string str;

int main(){
    cin >> n;
    cin >> str;
    for(long long i = 0; i < n; i++){
        if(str[i] == 'C') sum += 1;
        ans[i] = sum;
    }
    sum = 0;
    for(long long i = n - 1; i >= 0; i--){
        if(str[i] == 'W') sum += 1;
        num[i] = sum;
    }
    sum  = 0;
    for(long long i = 0; i < n; i++){
        if(str[i] == 'O'){
            sum += ans[i] * num[i];
        }
    }

    cout << sum;
    return 0;
}
