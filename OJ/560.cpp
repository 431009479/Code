/*************************************************************************
	> File Name: 560.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月30日 星期四 00时29分56秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int all, n, money[30], val[30], ans[30][30005];



int main(){
    cin >> all >> n;
    for(int i = 1; i <= n; i++){
        cin >> money[i] >> val[i];
        val[i] *= money[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= all; j++){
            if(j < money[i]){
                ans[i][j] = ans[i - 1][j];
            }else{
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - money[i]] + val[i]);
            }
        }
    }
    cout << ans[n][all] << endl;
    return 0;
}
