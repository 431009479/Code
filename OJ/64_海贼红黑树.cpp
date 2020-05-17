/*************************************************************************
	> File Name: 64_海贼红黑树.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 18时35分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define RED 0       //红色
#define BLACK 1     //黑色
#define DBLACK 2    //双重黑

typedef struct Node{
    int key;
    int color;// 颜色 ; 0 red, 1 black, 2 double black
    struct Node *lchild, *rchild;
}Node;

Node __NIL;   //替代空结点 NULL；
#define NIL (&__NIL)

__attribute__((constructor)) // 提现main函数之前运行

void init_NIL(){
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK;
    return ;
}

Node *getNewNode(int key){   // 初始化结点
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;  //初始化结点为红色
    return p;
}

//判断 root 孩子结点中是否有红色
bool has_red_child(Node *root){
    return root->lchild ->color == 0 || root ->rchild->color == 0;
}

    //左旋转
Node *left_rotate(Node *root){
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}
    //右旋转
Node *right_rotate(Node *root){
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

     //插入后的调整函数
Node *insert_maintain(Node *root){
    if(!has_red_child(root)) return root; // root 孩子结点中没有红色
    /*if(root->lchild->color == RED && root ->rchild->color == RED){ //root 孩子结点中都是红色
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }*/

    if(root->lchild->color == RED){ //root 孩子结点中只有左孩子是红色
        if(!has_red_child(root->lchild)) return root; //root 左孩子结点的两个孩子结点中没有红色
        if(root->lchild->rchild->color ==RED){ //root 左孩子结点的右孩子是红色 （LR型）
            root->lchild = left_rotate(root->lchild); //先小左旋转， 再大右旋转；
        }
        root = right_rotate(root); //root 左孩子结点的左孩子是红色 （LL型）； 直接大右旋转
    }else{ //root 孩子结点中只有右孩子是红色
        if(!has_red_child(root->rchild)) return root;//root 右孩子结点的两个孩子结点中没有红色
        if(root->rchild->lchild->color ==RED){ //root 右孩子结点的左孩子是红色 （RL型）
            root->rchild = right_rotate(root->rchild); //先小右旋转， 再大左旋转；
        }
        root = left_rotate(root); //root 右孩子结点的右孩子是红色 （RR型）； 直接大左旋转；
    }
    root->color = RED; // 旋转后root 变成红色
    root->lchild->color = root->rchild->color = BLACK; // 旋转后root两个孩子结点变成黑色
    return root;
}

    //求前驱
Node *predeccessor(Node *root){
    Node *temp = root->lchild;
    while(temp->rchild != NIL) temp = temp->rchild;
    return temp;
}


     //删除后的调整函数
Node *erase_maintian(Node *root){
    if(root->lchild->color != DBLACK &&
      root->rchild->color != DBLACK) return root;  ///没有双重黑的子结点
    if(has_red_child(root)){//双重黑兄弟节点为红 ，调整颜色和旋转， 兄弟节点是黑色的情况；
        root->color = RED;
        if(root->lchild->color == RED){
            root = right_rotate(root);
            root->rchild = erase_maintian(root->rchild);
        }else{
            root = left_rotate(root);
            root->lchild = erase_maintian(root->lchild);
        }
        root->color = BLACK;
        return root;
    }
    if((root->lchild->color == DBLACK && !has_red_child(root->rchild)) ||
       (root->rchild->color == DBLACK && !has_red_child(root->lchild))){
           root->color += 1;//双重黑色x 及 x 结点的”兄弟“节点是黑色及x 结点的 “兄弟”节点的两个孩子节点也是黑色。
           //调整方法：x节点的”兄弟“节点调整为红色,  x 节点 减少一重黑色。 x 结点的”父亲“节点 增加一重黑色。
           root->lchild->color -= 1;
           root->rchild->color -= 1;
           return root;
    }
    if(root->lchild->color == BLACK){
        if(root->rchild->rchild->color != RED){//RL  
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
        }
        root->rchild->color = root->color;//RR
        root->color = BLACK;
        root->lchild->color -= 1;
        left_rotate(root);
        root->rchild->color = BLACK;
    }else{
        if(root->lchild->lchild->color != RED){//LR
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
        }
        root->lchild->color = root->color;//LL
        root->color = BLACK;
        root->rchild->color -= 1;
        right_rotate(root);
        root->lchild->color = BLACK;    
    } 

}

//寻找适合的删除位置
Node *__erase(Node *root, int key){
    if(root == NIL) return root;
    if(root->key > key){
        root->lchild= __erase(root->lchild, key);
    }else if(root->key < key){
        root->rchild = __erase(root->rchild, key);
    }else{
        if(root->lchild == NIL || root->rchild == NIL){
            Node *temp = root->lchild = NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        }else{
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintian(root); //删除结点后，调整函数。
}



//删除结点
Node *erase(Node *root, int key){
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

//寻找适合的插入位置

Node *__insert(Node *root, int key){
    if(root == NIL) return getNewNode(key);
    if(root->key == key) return root;
    if(root->key > key){
        root->lchild = __insert(root->lchild, key);
    }else{
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root); //插入后的调整函数
}

//插入结点
Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}
//销毁
void clear(Node *root){
    if(root == NIL)return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

//遍历
void output(Node *root){
    if(root == NIL) return;
    output(root->lchild);
    printf("%d %d %d %d\n",
          root->key,
          root->color,
          root->lchild->key,
          root->rchild->key);
    output(root->rchild);
}



int main(){
  int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: output(root); break;
        }
    }
    return 0;
}

