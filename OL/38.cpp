/*************************************************************************
	> File Name: 38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月10日 星期三 17时11分48秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int cmp(int n){
    return floor(log10(n)) + 1;
}

int func(int n){
    int i = 1, ans = 0;
    while(cmp(ans) < 9){
        ans *= (int)pow(10, cmp(n * i));
        ans += n * i;
        i++;
    }
    if(cmp(ans) - 9) return 0;
    int num[10] = {1, 0};
    int tmp = ans;
    while(tmp){
        if(num[tmp % 10]) return 1;
        num[tmp % 10] = 1;
        tmp /= 10;
    }

    return ans;
}




int main(){
    int ans = 0;
    for(int i = 1; i < 10000; i++){
       int  temp  = func(i);
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
