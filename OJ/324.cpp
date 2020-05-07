/*************************************************************************
	> File Name: 324.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 17时36分58秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 5000000

struct UnionSet{
    int fa[N + 5], val[N + 5], size[N + 5];
    void init(int n){
        for(int i = 1; i <= n ; i++){
            fa[i] = i;
            size[i] = 1;
            val[i] = 0;
        }
        return ;
    }
    int get(int x){
        if(x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        return fa[x] = root;
    }
    void merge(int a, int b){
        int aa = get(a), bb= get(b);
        if(aa == bb) return ;
        fa[aa] = bb;
        val[aa] = size[bb];
        size[bb] += size[aa];
        return ;
    }


};
UnionSet u;
int main(){
    int n;
    scanf("%d", &n);
    char str[10];
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%s%d%d", str, &a, &b);
        switch(str[0]){
            case 'M': u.merge(a, b); break;
            case 'C':{
                if(u.get(a) - u.get(b)){
                    printf("-1\n")
                }else{
                    printf("%d\n",abs(u.val[a] - u.val[b]) - 1 );
                }
            }break;
        }
    
    }
    return 0;
}
