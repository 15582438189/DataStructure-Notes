#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *next;
    struct DNode *prior;
}DNode,*DLinkList;

DLinkList InitDList(){
    DNode *L=(DNode *)malloc(sizeof(DNode));
    L->next = NULL;
    L->prior = NULL;
    return L; 
}

int DListInsert(DLinkList L,int i,ElemType e){
    DNode *p = L;
    int j=0;
    while(p!=NULL && j < i-1){
        p = p->next;
        j++;
    }
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    if(p->next != NULL){
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return 1;
}

void PrintDList(DLinkList L){
    DNode *p = L->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int DListDel(DLinkList L,int i,ElemType *e){
    DNode *p = L;
    int j=0;
    while(p->next != NULL && j < i-1){
        p = p->next;
        j++;
    }
    DNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return 1;
}

DLinkList MergeList(DLinkList A,DLinkList B){
    DLinkList C = (DNode *)malloc(sizeof(DNode));
    C->next=NULL;
    C->prior=NULL;
    DNode *pc = C;
    DNode *pa = A->next;
    DNode *pb = B->next;
    while(pa != NULL && pb != NULL){
        if(pa->data <= pb->data){
            pc->next = pa;
            pa->prior = pc;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pb->prior = pc;
            pc = pb;
            pb = pb->next;
        }
    }
    if(pa != NULL){
        pc->next = pa;
        pa->prior = pc;
    }
    if(pb != NULL){
        pc->next = pb;
        pb->prior = pc;
    }
    free(A);
    free(B);
    return C;
}

int main(){
    DLinkList L=InitDList();
    if(L!=NULL && L->next==NULL && L->prior==NULL){
        printf("init is OK\n");
    }
    DListInsert(L,1,1);
    DListInsert(L,2,2);
    DListInsert(L,3,3);
    PrintDList(L);
    int val;
    DListDel(L,2,&val);
    PrintDList(L);
    //====归并测试示例====
    /*
    DLinkList La=InitDList();
    DLinkList Lb=InitDList();
    DListInsert(La,1,1);
    DListInsert(La,2,3);
    DListInsert(Lb,1,2);
    DListInsert(Lb,2,4);
    DLinkList Lc = MergeList(La,Lb);
    PrintDList(Lc);
    */
    return 1;
}