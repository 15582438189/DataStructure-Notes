#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
} htnode, *hfmt;

void inithfm(hfmt ht, int *w, int n){
    for (int i = 1; i <= n; i++){
        ht[i].weight = w[i - 1];
        ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
    }
}

void select1(hfmt ht, int n, int *s1, int *s2)
{
    int i;
    *s1 = 0;
    *s2 = 0;
    for (i = 1; i <= n; i++)
    {
        if (ht[i].parent == 0)
        {
            *s1 = i;
            break;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (ht[i].parent == 0 && i != *s1)
        {
            *s2 = i;
            break;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (ht[i].parent == 0)
        {
            if (ht[i].weight < ht[*s1].weight)
            {
                *s2 = *s1;
                *s1 = i;
            }
            else if (i != *s1 && ht[i].weight < ht[*s2].weight)
            {
                *s2 = i;
            }
        }
    }
    if (*s1 > *s2)
    {
        int t = *s1;
        *s1 = *s2;
        *s2 = t;
    }
}

void combine(hfmt ht, int i, int s1, int s2){
    ht[s1].parent = ht[s2].parent = i;
    ht[i].weight = ht[s1].weight + ht[s2].weight;
    ht[i].lchild = s1;
    ht[i].rchild = s2;
}

hfmt build(int *w, int n){
    int m = 2 * n - 1;
    hfmt ht = (hfmt)malloc( (size_t)(m + 1) * sizeof(htnode) );
    for (int i = 1; i <= m; i++){
        ht[i].weight = ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
    }
    inithfm(ht, w, n);
    for (int i = n + 1; i <= m; i++){
        int s1, s2;
        select1(ht, i - 1, &s1, &s2);
        combine(ht, i, s1, s2);
    }
    return ht;
}

int main(){
    int w[] = {70, 50, 20, 40};
    int n = 4;
    int m = 2 * n - 1;
    hfmt ht = build(w, n);
    printf("i weight parent lc rc\n");
    for (int i = 1; i <= m; i++){
        printf("%2d %3d %2d %2d %2d\n",i, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }
    free(ht);
    return 0;
}
