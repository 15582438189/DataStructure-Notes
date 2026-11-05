#include<stdio.h>
#include<stdlib.h>
#define mvnum 100
#define maxint 32767
typedef char vertextype;
typedef int edgetype;

typedef struct{
    vertextype vexs[mvnum]; 
    edgetype arcs[mvnum][mvnum];
    int vexnum,arcnum;
}amgraph;

int locatevex(amgraph g,vertextype u){
    for(int i=0;i<g.vexnum;i++){
        if(u==g.vexs[i])  return i;
    }
    return -1;
}

void createug(amgraph *g,vertextype vexs[],int n,vertextype v1[],vertextype v2[],int e){
    g->vexnum=n;
    g->arcnum=e;
    for(int i=0;i<n;i++){
        g->vexs[i]=vexs[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g->arcs[i][j]=0;
        }
    }
    for(int k=0;k<e;k++){
        int i=locatevex(*g,v1[k]);
        int j=locatevex(*g,v2[k]);
        g->arcs[i][j]=1;
        g->arcs[j][i]=1;
    }
}

int main(){
    vertextype vexs[]={'a','b','c','d','e','f'};
    vertextype v1[]={'a','a','a','b','c','d'};
    vertextype v2[]={'b','c','d','e','e','f'};
    int n=6,e=6;
    amgraph g;
    createug(&g,vexs,n,v1,v2,e);
    for(int j=0;j<n;j++){
        printf("%2c",g.vexs[j]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf(" %c",g.vexs[i]);
        for(int j=0;j<n;j++)
        {
            printf("%2d",g.arcs[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<g.vexnum;i++)
    {
        printf("%c=%d\n",vexs[i],locatevex(g,vexs[i]));
    }
    return 0;
}