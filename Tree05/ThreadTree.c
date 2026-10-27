#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char data;
    struct node *lchild;
    struct node *rchild;
    int ltag;
    int rtag;
}node,*tree;

node *pre = NULL; // 全局变量，保存上一个访问的结点，用来建线索

void inthreading(tree p){
    if(p == NULL) return;
    inthreading(p->lchild);
    //left threading
    if(p->lchild == NULL){
        p->lchild = pre;
        p->ltag = 1;
    }
    //right threading
    if(pre != NULL && pre->rchild == NULL){
        pre->rchild = p;
        pre->rtag = 1;
    }
    pre = p;
    inthreading(p->rchild);
}

node *firstnode(tree p){
    while(p->ltag == 0){
        p = p->lchild;
    }
    return p;
}

node *nextnode(node *p){
    if(p->rtag == 1){
        return p->rchild;
    }else{
        return firstnode(p->rchild);
    }
}

void inorder(tree t){
    node *p = firstnode(t);
    while(p != NULL){
        printf("%c ",p->data);
        p = nextnode(p);
    }
    printf("\n");
}

void create(tree *t){
    char ch;
    scanf("%c",&ch);
    if(ch == '#'){
        *t = NULL;
    }else{
        *t = (tree)malloc(sizeof(node));
        (*t)->data = ch;
        (*t)->ltag = 0;
        (*t)->rtag = 0;
        (*t)->lchild = NULL;
        (*t)->rchild = NULL;
        create(&(*t)->lchild);
        create(&(*t)->rchild);
    }
}

int main(){
    tree t;
    printf("please input tree:\n");
    printf("input:");
    create(&t);
    pre = NULL;
    inthreading(t);
    printf("inorder threadin:");
    inorder(t);
    return 0;
}