/*************************************************************************
	> File Name: 6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月17日 星期一 18时30分57秒
 ************************************************************************/
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>

 typedef struct Node{
    int data;
    struct Node *next;
 }Node;

 typedef struct list{
     Node head;
     int n;
 }list;
 Node *getNewNode(int val){
     Node *p = (Node *)malloc(sizeof(Node));
     p->data = val;
     p->next = NULL;
     return p;
 }
 list *getNewlist(){
     list * l = (list *)malloc(sizeof(list));
     l->head.next = NULL;
     l->n = 0;
     return l;
 }

 int  insert(list *l, int ind, int val){
     if(l == NULL) return 0;
     if(ind < 0 || ind > l->n)return 0;
     Node *p = &(l->head), *q = getNewNode(val);
     while(ind--)p = p->next;
     q->next = p->next;
     p->next = q;
     l->n ++;
     return 1;
 }
 int empty(list *l , int ind){
     if(l == NULL) return 0;
     if(ind < 0 || ind >= l->n)return 0;
     Node *p = &(l->head), *q;
     while(ind--)p = p->next ;
     q = p->next;
     p->next = q->next;
     free(q);
     l->n--;
     return 1;
 }

 void rev(list *l){
     if( l== NULL) return ;
     Node * p = l->head.next, *q;
     l->head.next = NULL;
     while(p){
         q = p->next;
         p->next = l->head.next;
         l->head.next =p;
         p = q;
     }
     return ;
 }
 void output(list *l){
     printf("list(%d) = [", l->n);
     for(Node *p = l->head.next; p ; p = p->next){
         printf("%d->",p->data);
     }
     printf("NULL]\n");
 }



void clear_Node(Node *node){
    if(node == NULL) return ;
    free(node);
    return ;
}

void clear_list(list *l){
     if(l == NULL) return;
     Node *p = l->head.next, *q;
     while(p){
         q = p->next;
         clear_Node(p);
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
        ind = rand() %(l->n + 3) - 1;
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
                printf("erase %d at %d to list = %d\n", ind, empty(l, ind));
            }break;
        }
        output(l);
        printf("\n");
    }
    clear_list(l);

     return 0;
 }

