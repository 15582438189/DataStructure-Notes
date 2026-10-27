#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tnode{
    char data;
    struct tnode *lchild;
    struct tnode *rchild;
}tnode,*tree;

tree init(){
    tnode *a=(tnode *)malloc(sizeof(tnode));
    tnode *b=(tnode *)malloc(sizeof(tnode));
    tnode *c=(tnode *)malloc(sizeof(tnode));
    tnode *d=(tnode *)malloc(sizeof(tnode));
    tnode *e=(tnode *)malloc(sizeof(tnode));
    tnode *f=(tnode *)malloc(sizeof(tnode));
    tnode *g=(tnode *)malloc(sizeof(tnode));
    a->data='a';b->data='b';c->data='c';
    d->data='d';e->data='e';f->data='f';
    g->data='g';
    a->lchild=b;a->rchild=c;
    b->lchild=d;b->rchild=e;
    d->lchild=NULL;d->rchild=NULL;
    e->lchild=NULL;e->rchild=NULL;
    c->lchild=f;c->rchild=NULL;
    f->lchild=NULL;f->rchild=g;
    g->lchild=NULL;g->rchild=NULL;
    return a;
}

void print(tree t,int depth){
    if(t==NULL) return;
    print(t->rchild,depth+1);
    for(int i=0;i<depth;i++) printf("- ");
    printf("%c\n",t->data);
    print(t->lchild,depth+1);
}

void pre(tree t){
    if(t==NULL) return;
    printf("%c ",t->data);
    pre(t->lchild);
    pre(t->rchild);
}

void inorder(tree t){
    tree stack[100];
    int top=-1;
    tree p=t;
    while(p!=NULL || top != -1){
        if(p!=NULL){
            stack[++top]=p;
            p=p->lchild;
        }else{
            p=stack[top--];
            printf("%c ",p->data);
            p=p->rchild;
        }
    }
}

int main(){
    tree t=init();
    print(t,0);
    pre(t);
    printf("\n");
    inorder(t);
    return 0;
}