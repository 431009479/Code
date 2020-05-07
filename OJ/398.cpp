/*************************************************************************
	> File Name: 398.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月01日 星期三 18时48分49秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct node{
    int x, y, step;
}

int n, m, sx, sy;
int mmap[405][405];

int dir[8][2] = {
    1, 2, 1, -2, 2, 1, 2, -1,
    -1, 2, -1, -2, -2, 1, -2, -1
};


int main(){
    cin >> n >> m >> sx >> sy;
    queue<node> que;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
             mmap[i][j] = 0;

    que.push({sx, sy, 0});
    mmap[sx][sy] = -1;

     while(!que.empty()){
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 8; i++){
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x < 1 || y < 1 || x > n || y > m || mmap[x][y]) continue;
            mmap[x][y] = temp.step + 1;
            que.push({x, y, mmap[x][y]});
        }
    }
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j != 1) cout <<" ";
            if(mmap[i][j] == -1) cout <<"0"; 
            else cout << mmap[i][j];
        }
          cout << '\n';
      }
    return 0;
}
