/*************************************************************************
	> File Name: 72.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月26日 星期日 22时59分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 10005

struct UnionSet {
    int fa[M];
    int val[M];
    void init(int n){
        for(int i = 1; i <= n; i++) 
            fa[i] = i, val[i] = 0;
    }
    int get(int x){
        if(x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    void merge(int a, int b, int c){
        int aa = get(a), bb = get(b);
        if(aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }
};

UnionSet u;
void read(int &n, int &m){
    cin >> n >> m;
    u.init(n);
    return ;
}

int main(){
    int n, m;
    read(n, m);
    for(int i = 1; i <=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            u.merge(b, c, 2);
        }else{
            if(u.get(b) != u.get(c)){
                cout << "Unknown" << endl;
            }else{
                switch((u.val[b] - u.val[c] + 3) % 3){
                    case 0: cout << "Tie" << endl; break;
                    case 1: cout << "Loss" << endl; break;
                    case 2: cout << "Win" << endl; break;
                }
            }
        }
    }

    return 0;
}
