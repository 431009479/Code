/*************************************************************************
	> File Name: 588_数列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时27分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

int ans[31][1000000] = {{}, {1}}, n;


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int ind = 0;
        for(int j = 0; ans[i - 1][j] != 0; j++){
            int x = 1;
            while(ans[i - 1][j] == ans[i - 1][j + 1]){
                x++; j++;
            }
            ans[i][ind++] = x;
            ans[i][ind++] = ans[i - 1][j];
        }
    }
    for(int i = 0; ans[n][i] != 0; i++){
        cout << ans[n][i];
    }
    cout << '\n';

    return 0;
}
