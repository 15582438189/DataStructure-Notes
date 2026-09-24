#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList InitList(){
    LNode *L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    return L;
}

void HeadInsert(LinkList L,ElemType e){
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=L->next;
    L->next=s;
}

void TailInsert(LinkList L,ElemType e){
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=NULL;
    LNode *p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=s;
}

void PrintList(LinkList L){
    for(LNode *p=L->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
}

int ListInsert(LinkList L,int i,ElemType e){
    if(i<1) return 0;
    LNode *p=L;
    int j=0;
    while(p!=NULL && j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL) return 0;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 1;
}

int ListDel(LinkList L,int i,ElemType *e){
    if(i<1) return 0;
    LNode *p=L;
    int j=0;
    while(p!=NULL && j<i-1){
        p=p->next;
        j++;
    }
    if(p->next==NULL) return 0;
    LNode *q=p->next;
    *e=q->data;
    p->next=q->next;
    free(q);
    return 1;
}

int GetElem(LinkList L,int i,ElemType *e){
    if(i<1) return 0;
    LNode *p=L->next;
    int j=1;
    while(p!=NULL && j<i){
        p=p->next;
        j++;
    }
    if(p==NULL) return 0;
    *e=p->data;
    return 1;
}

int main(){
    LinkList L=InitList();
    printf("node next is: %s\n",L->next);

    HeadInsert(L,1);
    HeadInsert(L,2);
    HeadInsert(L,3);
    PrintList(L);

    TailInsert(L,1);
    TailInsert(L,2);
    TailInsert(L,3);
    PrintList(L);

    ListInsert(L,2,100);
    PrintList(L);
    int val;
    ListDel(L,2,&val);
    PrintList(L);
    int x;
    if(GetElem(L,2,&x)) printf("the del is%d\n",x);
    PrintList(L);
    return 0;
}