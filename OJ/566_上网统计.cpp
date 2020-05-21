/*************************************************************************
	> File Name: 566_上网统计.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月19日 星期二 00时50分24秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;


string str[1005][5005], rew[1005];
int n, m, num[1005];

int flat;

map<string, int> a;



int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(a[s1] == 0){
            flat++;
            rew[flat] = s1;
            a[s1] = flat;
        }
        int x = a[s1];
        str[x][num[x]] = s2;
        num[x]++;
    }
    for(int i = 1; i <= flat; i++){
        cout << rew[i];
        int x = a[rew[i]];
        for(int j = 0; j < num[i]; j++){
            cout << " " << str[x][j];
        }
        cout << endl;
    }

    return 0;
}
