#include <stdio.h>
#include <stdlib.h>

typedef struct qnode{
    int data;
    struct qnode *next;
}qnode;

typedef struct{
    qnode *front;
    qnode *rear;
}linkq;

int initq(linkq *q){
    qnode *h = (qnode *)malloc(sizeof(qnode));
    h->next = NULL;
    q->front = h;
    q->rear = h;
    return 1;
}

int insert(linkq *q,int e){
    qnode *p = (qnode *)malloc(sizeof(qnode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return 1;
}

void printq(linkq q){
    qnode *p = q.front->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int del(linkq *q,int *e){
    qnode *p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p){
        q->rear = q->front;
    }
    free(p);
    return 1;
}

int main(){
    linkq q;
    initq(&q);
    if(q.front == q.rear) printf("init ok\n");
    printf("front=%p,rear=%p\n",q.front,q.rear);
    printf("q=%p\n",&q);

    insert(&q,11);
    insert(&q,22);
    insert(&q,33);
    printq(q);
    int x;
    del(&q,&x);
    printq(q);
    return 1;
}