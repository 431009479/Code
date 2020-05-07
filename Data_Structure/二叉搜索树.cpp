/*************************************************************************
	> File Name: 二.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 16时37分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int k;
    struct Node *l , *r;
}Node;

Node *getNewNode(int k){
    Node *p = (Node *)malloc(sizeof(Node));
    p->k = k;
    p->l = p->r = NULL;
    return p;
}

Node *insert(Node *root, int k){
    if(root == NULL)return getNewNode(k);
    if(root->k == k) return root;
    if(k < root->k) root->l = insert(root->l, k);
    else root->r = insert(root->r, k);
    return root;
}

Node *predecssor(Node *root){
    Node *temp = root->l;
    while(temp ->r) temp = temp ->r;
    return temp;
}

Node *erase(Node *root, int k){
    if(root == NULL) return root;
    if(k < root->k) root->l = erase(root->l, k);
    else if(k > root->k) root->r = erase(root ->r, k);
    else{
        if(root->l == NULL || root ->r == NULL){
        Node *temp = root ->l ? root ->l :root ->r;
        free(root);
        return temp;
        }else{
            Node *tmep = predecssor(root);
            root->k = tmep->k;
            root->l = erase(root->l, tmep->k);
        }
    }
    return root; 
}

void __in_order(Node * root){
    if(root == NULL) return ;
    __in_order(root->l);
    printf("%d ", root->k);
    __in_order(root->r);
    return ;
}
void in_order(Node *node){
    printf("in order output : ");
    __in_order(node);
    printf("\n");
    return ;
}

void clear(Node *root){
    if(root == NULL) return ;
    clear(root->l);
    clear(root->r);
    free(root);
    return ;
}

int main(){
    int op, val;
    Node *root = NULL;
    while(~scanf("%d%d", &op, &val)){
        switch(op){
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        in_order(root);
    }
    clear(root);
    return 0;
}

