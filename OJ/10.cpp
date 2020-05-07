/*    > Author:    hug
  > Problem:   树和二叉树的复习-递归删除指定节点
  > Mail:      hug@haizeix.com
************************************************************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char data;
    struct Node *l, *r;
}Node, *pNode;

pNode init(char c){
    pNode p = (pNode)malloc(sizeof(Node));
    p->data = c;
    p->l = p->r = NULL;
    return p;
}
void clear(pNode p){
    if(p == NULL) return ;
    if(p->l) clear(p->l);
    if(p->r) clear(p->r);
    return ;
}
void output(pNode p){
    if(p == NULL) return ;
    printf("%c",p->data);
    if(p->l == NULL && p->r == NULL) return ;
    printf("(");
    if(p->l) output(p->l);
    if(p->r){printf(","); output(p->r);}
    printf(")");
    return ;
}

pNode arr[26];
int main(){
    char str[4];
    pNode root = NULL, p = NULL;
    while(~scanf("%s", str)){
        if(str[0] == str[1] && str[0] == '^'){
            break;
        }
        p = init(str[1]);
        arr[str[1] - 'A'] = p;
        if(str[0] == '^') root = p;
        else{
            switch(str[2]){
                case 'L':
                    arr[str[0] - 'A']->l = p;
                break;
                case 'R':
                    arr[str[0] - 'A']->r = p;
                break;
            }
        }
    }
    output(root);
    printf("\n");
    clear(root);
    return 0;
}
