/*************************************************************************
	> File Name: 400.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 11时11分37秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x, y, step;
};

int dir[12][2]{
    1, 2, 1, -2, -1, 2, -1, -2,
    2, 1, 2, -1, -2, 1, -2, -1,
    2, 2, 2, -2, -2, 2, -2, -2,
};
int n, sx, sy, ans[505][505], check[505][505];


int main(){
    queue<node>que;
    que.push({1, 1, 0});
    check[1][1] = 1;
        while(!que.empty()){
            node temp = que.front();
            que.pop();
            for(int i = 0; i < 12; i++){
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if(x <= 0 || y <= 0 || x > 500 || y > 500) continue;
                if(check[x][y] == 0){
                    check[x][y] = 1;
                    ans[x][y] = temp.step + 1;
                    que.push({x, y, temp.step + 1});
                }
            }
        }
        cin >> n;
    for(int i = 0; i < n; i++){
        cin >> sx >> sy;
        cout << ans[sx][sy] <<'\n';
    }
    return 0;
}
