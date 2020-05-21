/*************************************************************************
	> File Name: 598_MySQL.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月21日 星期四 00时07分06秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

struct Node{
    string str[55];
};

Node arr[505];
int n, m;
int num[55];

int main(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i].str[j];
            if(arr[i].str[j].size() > num[j]){
                num[j] = arr[i].str[j].size();
            }
        }
    }
    int sum = 0;

    for(int i = 0; i < m; i++){
        sum += num[i] + 3;
    }
    for(int i = 0; i <= 7 + n * 2; i++){
        for(int j = 0; j <= sum + 1; j++){
            if(i == 0) {
                for(int k = 0; k < m; k++){
                    cout <<"+-";
                    for(int t = 0; t <= num[k]; t++){
                        cout <<"-";
                    }
                    cout <<"-+";
                }
            }
        }
    }


    return 0;
}
