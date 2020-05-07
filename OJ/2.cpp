/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月16日 星期日 20时45分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct listNode{
    int data;
    struct listNode *next;
}listNode;

typedef struct list{
    listNode head; // 虚拟头， listNode *head  头指针
    int length;
}list;

listNode *getNewNode(int val){
    listNode *p = (listNode *)malloc(sizeof(listNode));
    p->data = val;
    p->next = NULL;
    return p;
}

list *getNewlist(){
    list *l = (list *)malloc(sizeof(list));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(list *l, int ind, int val){
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->length) return 0;
    listNode *p = &(l->head), *node = getNewNode(val);
    while(ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length++;
    return 1;
}

int erase(list *l, int ind){
    if(l == NULL) return 0;
    if(ind < 0 || ind >= l->length) return 0;
    listNode *p = &(l->head), *q;
    while(ind--)p = p->next;
    q = p -> next;
    p->next = q->next;
    free(q);
    l->length--;
    return 1;
}

void rev(list *l){
    if(l == NULL) return ;
    listNode *p = l->head.next, *q;
    l->head.next = NULL;
    while(p){
        q = p->next;
        p -> next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return;
}
void output(list *l){
    printf("list(%d) = [",l->length);
    for(listNode *p = l->head.next; p; p = p->next){
        printf("%d->",p->data);
    }
    printf("NULL]\n");
    return ;
}

void clear_listNode(listNode *node){
    if(node == NULL) return ;
    free(node);
    return ;
}

void clear_list(list *l){
    if(l == NULL) return ;
    listNode *p = l->head.next, *q;
    while(p){
        q = p->next;
        clear_listNode(p);
        p = q;
    }
    free(l);
    return ;
}


int main(){
    srand(time(0));
    #define max_op 20
    list *l = getNewlist();
    int op, ind, val;
    for(int i = 0; i < max_op; i++){
        op = rand() % 4;
        val = rand() % 100;
        ind = rand() %(l->length + 3) - 1;
        switch(op){
            case 0:
            case 1:{
                printf("insert %d at %d to list = %d\n", val, ind, insert(l, ind, val));
            }break;
            case 2:{
                printf("reverse the list\n");
                rev(l);
            }break;
            case 3:{
                printf("erase %d at %d to list = %d\n", ind, erase(l, ind));
            }break;
        }
        output(l);
        printf("\n");
    }
    clear_list(l);
    return 0;
}
