#include<stdio.h>

#define MAX 100
typedef int ElemType;

typedef struct{
    ElemType data[MAX];
    int len;
}SeqList;

SeqList InitList(){
    SeqList L;
    L.len=0;
    return L;
}

SeqList ListInsert(SeqList L,int i,ElemType e){
    if(i<1||i>L.len+1) return L;
    if(L.len>=MAX) return L;
    for(int j=L.len;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.len++;
    return L;
}

SeqList ListDel(SeqList L,int i,ElemType *e){
    if(i<1||i>L.len) return L;
    *e=L.data[i-1];
    for(int j=i;j<L.len;j++){
        L.data[j-1]=L.data[j];
    }
    L.len--;
    return L;
}

int GetElem(SeqList L,int i,ElemType *e){
    if(i<1||i>L.len) return 0;
    *e=L.data[i-1];
    return 1;
}

int LocateElem(SeqList L,ElemType e){
    for(int i=0;i<L.len;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

void PrintList(SeqList L){
    for(int i=0;i<L.len;i++){
        printf("%d ",L.data[i]);
    }
}

int main(){
    SeqList L=InitList();
    printf("%d\n",L.len);
    L=ListInsert(L,1,1);
    L=ListInsert(L,2,2);
    L=ListInsert(L,3,3);
    L=ListInsert(L,4,4);
    printf("len=%d\n",L.len);
    PrintList(L);
    printf("\n");
    int e;
    L=ListDel(L,3,&e);
    printf("%d\n",e);
    PrintList(L);

    printf("\n");
    if(GetElem(L,1,&e)) printf("%d\n",e);
    if(LocateElem(L,2)) printf("%d\n",LocateElem(L,2));
    return 0;
}