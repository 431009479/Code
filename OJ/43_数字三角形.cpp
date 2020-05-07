/*************************************************************************
	> File Name: 43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 20时13分06秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#include<iostream>
using namespace std;
#include<algorithm>
#define max  1000
int a[max + 5][max + 5] = {0};
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++)
                cin >> a[i][j];
    }
    for(int i = n - 1; i >= 1;i--){
        for(int j = 1; j <= i; j++){
            a[i][j] +=  a[i + 1][j] > a[i + 1][j + 1] ? a[i + 1][j] : a[i + 1][j + 1];
        }
    }
    cout << a[1][1]<<endl;
    return 0;
}
