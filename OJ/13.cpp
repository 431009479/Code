/*************************************************************************
	> File Name: 13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月21日 星期五 17时22分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define swap(a, b) { \
__typeof(a) __temp; \
__temp = (a); \
(a) = (b); \
(b) = __temp; \
}

 

typedef struct Node{
    int ind, f;
}Node;
typedef struct Heap{
    Node *data;
    int size, length;
}Heap;

int cmp(Node a, Node b){
    if(a.f > b.f) return 1;
    if(a.f == b.f && a.ind <b.ind) return 1;
    return 0;
}
void init_heap(Heap *h, int n) {

    h->data = (Node *)malloc(sizeof(Node) * n);

    h->length = n;

    h->size = 0;

}
void push(Heap *h, Node value){
    if(h->size >= h->length) return;
    h->data[h->size] = value;
    int ind, f;
    ind = h->size;
    f = (ind - 1) / 2;
    while(cmp(h->data[ind], h->data[f])){
        swap(h->data[ind], h->data[f]);
        ind = f; f = (ind - 1) / 2;
    }
    h->size++;
}
void update(Heap *h, int i, int n){
    int l, r, m;
    l = i *2 + 1;
    r = i *2 + 2;
    m = i;
    if(l < n && cmp(h->data[l],h->data[m])){
        m = l;
    }
    if(r < n && cmp(h->data[r], h->data[m])){
        m = r;
    }
    if(m != i){
        swap(h->data[m], h->data[i]);
        update(h, m, n);
    }
}
Node top(Heap * h){
    return h->data[0];
}

void pop(Heap *h){
    if(h->size == 0) return;
    h->size--;
    swap(h->data[0], h->data[h->size]);
    update(h, 0, h->size);
}

int empty(Heap *h){
    return h->size == 0;
}
void clear(Heap *h){
    free(h->data);
    free(h);
}

int main(){
    int t, n, ind;
    scanf("%d", &t);
    Heap *h[101];
    for(int i = 1; i <= 100; i++){
        h[i] = (Heap *)malloc(sizeof(Heap));
        init_heap(h[i], 50000);
    }
    while(ind < t){
        printf("Case #%d:\n", ++ind);
        scanf("%d", &n);
        Node zoom;
        int s;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &zoom.f, &s);
            zoom.ind = i + 1;
            push(h[s], zoom);
        }
        for(int i = 0; i < n; i++){
            int m = -1;
            Node zoom1, zoom2;
            for(int j = 1; j <= 100; j++){
                if(empty(h[j]))continue;
                if(m == -1){m = j; continue;}
                zoom1 = top(h[m]);
                zoom2 = top(h[j]);
                zoom1.f = zoom1.f + i * m;
                zoom2.f = zoom2.f + i * j;
                if(cmp(zoom2,zoom1)){
                    m = j;
                }
            }
            printf("%d", top(h[m]).ind);
            pop(h[m]);
            if(i != n -1){
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i = 1; i <= 100; i++){
        clear(h[i]);
    }
    return 0;
}
