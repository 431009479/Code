/*************************************************************************
	> File Name: 哈希表.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 14时43分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    char *str;
    struct Node *next;
}Node;
typedef struct Hx{
    Node **data;
    int size;
}Hx;
Node *init_node(char *str, Node *head){
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next - head;
    return p;
}


Hx *init_Hx(int n){
    Hx *h = (Hx *)malloc(sizeof(Hx));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

int BKDRHash(char *str){
    int seed = 31, hash = 0;
    for(int i = 0; str[i]; i++){
        hash = hash * seed + str[i];
    }
    return hash & 0X7fffffff;
}

int insert(Hx * h, char *str){
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

int search(Hx *h, char *str){
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while(p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}



void clear_node(Node *node){
    if(node == NULL) return ;
    Node *p = node, *p;
    while(p){
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    free(q);
    return ;
}
void clear_Hx(Hx * h){
    if( h == NULL) return ;
    for()
}
int main(){
    srand(time(0));
    int op;
    #define max_op 100
    char *str[max_op + 5];
    Hx *h = init_Hx(max_op + 5);
    while(~scanf("%s", &op, str)){
        switch(op){
            case 0 :
            printf("insert %s to hash table\n", str);
            insert(h, str);
            break;
            case 1:
            printf(" %s to hash tablp\n", str){
                
            }
        }
    }

    return 0;
}
