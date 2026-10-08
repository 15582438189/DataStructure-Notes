#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
#define max1 50
typedef struct{
    int data[max1];
    int front;
    int rear;
}sxdl;

void initdl(sxdl *q){
    q->front = 0;
    q->rear = 0;
}

int insertdl(sxdl *q,int e){
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % max1;
    return 1;
}

int deldl(sxdl *q,int *e){
    *e = q->data[q->front];
    q->front = (q->front + 1) % max1;
    return 1;
}

int main(){
    sxdl q;
    initdl(&q);
    if(q.front == q.rear){
        printf("init ok\n");
    }
    
    insertdl(&q,11);
    insertdl(&q,22);
    insertdl(&q,33);
    printf("len=%d\n",(q.rear - q.front + max1) % max1);
    int x;
    deldl(&q,&x);
    printf("x=%d,len=%d\n",x,(q.rear - q.front + max1) % max1);
    return 1;
}