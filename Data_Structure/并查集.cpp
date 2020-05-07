/*************************************************************************
	> File Name: 查并集.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 18时33分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(a, b){\
    a ^= b; b ^= a; a ^= b;\
}

int max(int a, int b){
    if(a > b) return a;
    return b;
}

typedef struct Node{
    int *fal, *num;
    int n;
}Node;

Node *init(int n){
    Node *h = (Node *)malloc(sizeof(Node));
    h->fal = (int *)malloc(sizeof(int) * (n + 1));
    h->num = (int *)malloc(sizeof(int) *(n + 1));
    h->n = n;
    for(int i = 1; i <= n; i++){
        h->fal[i] = i;
        h->num[i] = 1;
    }
    return h;
}

int find(Node *h, int x){
    return h->fal[x] = (h->fal[x] == x ? x : find(h, h->fal[x]));

}
int merge(Node *h, int a, int b){
    int x = find(h, a);
    int y = find(h, b);
    if(x == y) return 0;
    if(h->num[x] < h->num[y]) swap(h->num[x], h->num[y]);
        h->fal[y] = x;
        h->num[x] += h->num[y];
    return 1;
}

void clear(Node *node){
    free(node->fal);
    free(node->num);
    free(node);
    return ;
}


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    Node *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No"); break;
        }
    }
    clear(u);
    return 0;
}


