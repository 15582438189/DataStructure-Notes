#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef int ElemType;
typedef struct{
    ElemType data[MAX];
    int top;
} SqStack;

int InitStack(SqStack *s){
    s->top = 0;
    return 1;
}

int StackEmpty(SqStack s){
    return s.top == 0;
}

int Push(SqStack *s, ElemType e){
    s->data[s->top] = e;
    s->top++;
    return 1;
}

int Pop(SqStack *s, ElemType *e){
    s->top--;
    *e = s->data[s->top];
    return 1;
}

void PrintStack(SqStack *s){
    int my=s->top;
    while(my != 0){
        my--;
        printf("%d ", s->data[my]);
    }
    printf("\n");
}

int main(){
    SqStack s;
    InitStack(&s);
    printf("after init,the top=%d\n", s.top);

    Push(&s,10);
    Push(&s,20);
    Push(&s,30);
    printf("after insert,top=%d\n", s.top);
    printf("is ti empty? %s\n", StackEmpty(s)?"Y":"N");
    PrintStack(&s);
    Push(&s,100);
    PrintStack(&s);
    int x;
    Pop(&s, &x);
    printf("after pop,x=%d\n",x);
    PrintStack(&s);

    return 0;
}