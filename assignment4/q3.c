#include<stdio.h>
#include<stdlib.h>

struct node {
  int rank;
  int parent;
};
typedef struct node * nodePointer;

struct node makeset(int x){
  struct node addSet;
  addSet.rank = 0;
  addSet.parent = x;
  return addSet;
}

int find(nodePointer p, int val){
  if(p[val].parent != val)
  	p[val].parent = find(p, p[val].parent);
  return p[val].parent;
}

void link(nodePointer p, int val1, int val2){
  if(p[val1].rank > p[val2].rank){
  	p[val2].parent = val1;
  }
  else{
  	p[val1].parent = val2;
    if(p[val1].rank == p[val2].rank)
     p[val2].rank = p[val2].rank+1;
  }
  return;
}
// This function is used for set union
void unionset(nodePointer p, int val1, int val2){
  link(p,find(p,val1),find(p,val2));
  return;
}
// This function is used by qSort()
int cmpfunc (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}
int main(void)
{
  int v,e;
  scanf("%d",&v);
  scanf("%d",&e);

  int i=0, j=0;
  struct node nodeVertex[v];
  for(i=0; i<v; i++)
  	nodeVertex[i] = makeset(i);
  
// read from console
  int in1, in2;
  for(j=0; j<e; j++){
  	scanf("%d %d",&in1, &in2);
    unionset(nodeVertex,in1,in2);
  }

  int visit[v];
  for(i=0; i<v; i++)
  	visit[i]  = 0;

  for(i=0; i<v; i++)
  	visit[find(nodeVertex,i)]++;
  
  int tot = 0;
  for(i=0; i<v; i++)
  	if(visit[i] > 0) tot++;


  printf("%d\n",tot);
  int componentSize[tot];
  j=0;
  for(i=0; i<v; i++){
    if(visit[i] > 0){
    	componentSize[j] = visit[i];
        j++;
    }
  }
// quickSort - C library function for sorting the array  
  qsort(componentSize, tot, sizeof(int), cmpfunc);
  for(i=0; i<tot; i++)
    printf("%d ",componentSize[i]);

  return 0;
}