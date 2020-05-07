/*************************************************************************
	> File Name: 551_最长不上升子序列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 15时50分28秒
 ************************************************************************/


#include<iostream>
#include<algorithm>
using namespace std;

int a[10000001];
int b[10000001];

int main(){
    int n, k;
    cin >> n;
    b[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    b[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] <= b[b[0]])  b[++b[0]] = a[i];
        else {
            for(int j = 1; j < i; j++){
                if(b[j] < a[i]){
                     k = j;
                    break;
                }
            }
           //cout <<b[k] << " " << a[i] <<'\n';
            b[k] = a[i];
        }

    }
    
    cout << b[0];
    return 0;
}
