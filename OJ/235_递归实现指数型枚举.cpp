/*************************************************************************
	> File Name: 235_递归实现指数型枚举.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 16时02分06秒
 ************************************************************************/


#include<iostream>
using namespace std;
char num[30];
int cnt, n, m;

void p(int k){
    if(k == 1){
        for(int i = 0; i < cnt; i++){
            cout <<num[i];
        }
        cout << '\n';
        return ;
    }   
}

void func(int s){
    for(int i = s;  i <= n; i++){
        num[cnt++] = (char)(i + 64);
        p(m--);
        func(i + 1);
        cnt--;
    }
}

int main(){
    cin >> n >> m;
    func(1);
    return 0;
}

