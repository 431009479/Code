/*************************************************************************
	> File Name: 399.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 19时39分22秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x, y, step;
};

int n, m;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
char str[505][505];
queue<node> que;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> str[i][j];
            if(str[i][j] == 's'){
                que.push({i, j, 0});
            }
        }
    }
    while(!que.empty()){
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(str[x][y] == 'g'){
                cout << temp.step + 1 << endl;
                return 0;
            }
            if(str[x][y] == '.'){
                str[x][y] = 0;
                que.push({x, y, temp.step + 1});
                
            }
        }

    }
    cout << "No" << endl;
    return 0;
}
