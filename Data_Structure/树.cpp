/*************************************************************************
	> File Name: 树.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 14时13分18秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int data;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree{
    Node *root;
    int n;
}Tree;
    //创建结点
Node *getNewNode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}
    //创建树
Tree *getNewTree(){
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree ->root = NULL;
    tree ->n = 0;
    return tree;
}
    //向树内加入结点
Node *insertNode(Node *root, int val, int *ret){
    if(root == NULL) {
        *ret = 1;
        return getNewNode(val);}
    if(root->data == val) return root;
    if(val < root -> data) root->lchild = insertNode(root->lchild, val, ret);
    else root->rchild = insertNode(root->rchild, val, ret);
    return root;
}

void insert(Tree *tree, int val){
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag);
    tree ->n += flag;
    return;
}
    //遍历广义表
void outputNode(Node *root){
    if(root == NULL) return;
    printf("%d", root->data);
    if(root -> lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
}
           
void output(Tree *tree){
    printf("tree (%d) = ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;
}
    //先序遍历
void pre_orderNode(Node *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return ;
}
          
void pre_order(Tree *tree){
    printf("pre_order : ");
    pre_orderNode(tree -> root);
    printf("\n");
}
    //中序遍历
void in_orderNode(Node *root){
    if(root == NULL) return;
    in_orderNode(root->lchild);
    printf("%d ", root->data);
    in_orderNode(root->rchild);
    return ;
}

void in_order(Tree *tree){
    printf("in_order : ");
    in_orderNode(tree -> root);
    printf("\n");
}
    //后序遍历
void post_orderNode(Node *root){
    if(root == NULL) return;
    post_orderNode(root->lchild);
    post_orderNode(root->rchild);
    printf("%d ", root->data);
    return ;
}

void post_order(Tree *tree){
    printf("post_order : ");
    post_orderNode(tree -> root);
    printf("\n");
}
    //销毁结点
void clear(Node *node){
    if(node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
}  
    //销毁树
void clear_tree(Tree *tree){
    if(tree == NULL) return ;
    clear(tree->root);
    free(tree);
    return ;
}

int main(){
    srand(time(0));
    Tree *tree = getNewTree();
    #define max_op 10
    for(int i = 1; i <= max_op; i++){
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);
    return 0;
}
