/*************************************************************************
	> File Name: 528.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 16时35分17秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node{
    int num, ans;
};

int x, y, n, num[105][105], check[105];


int main(){
    cin >> n >> x >> y;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> num[i][j];
        }
    }
    queue<node> que;
    que.push({x, 0});
    while(!que.empty()){
        node temp = que.front();
        que.pop();
        for(int i = 1; i <= n; i++){
            if(num[temp.num][i] && check[i] == 0){
                if(i == y){
                    cout << temp.ans <<'\n';
                    return 0;
                }else{

                    que.push({i, temp.ans + 1});
                    check[i] = 1;
                }
            }
        }

    }
}
