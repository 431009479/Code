/*************************************************************************
	> File Name: 42.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月28日 星期二 18时36分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 20
#define N 10000
int f[M][N];
int val[M];

int main(){
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> val[i];
    }
    for(int i = 1; i <= m; i++){
        f[i][0] = 1;
        for(int j = 1; j <= n; j++){
            f[i][j] = f[i - 1][j];
            if(j >= val[i]) f[i][j] += f[i][j - val[i]];
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;

    return 0;
}
