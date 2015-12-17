#include<stdio.h>
#include<stdlib.h>

int *array = NULL;
int stackIndex[2]={-2,-2}, total=0;
int arraySize=0;

char opNames[4][8] = {"push","pop","peek","isEmpty"};

int tot0,tot1,s0,s1;

void init(int num)
{	arraySize=num;
	array=  (int *) malloc (sizeof(int) * (num));
 	//tot0=tot1=s0=0; 
 	//s1=num-1;
 tot0=s0=s1=0;
 tot1=num-1;
}
void cleanup()
{
	free(array);
}
int push(int stack, int val)
{
  if((s0+s1)==arraySize)
    return -1;
  if(stack==0){
  array[tot0]=val;
    tot0++;
    s0++;
  }
  else
  {
    array[tot1]=val;
    tot1--;
    s1++;
  }
  return 1;

}

int pop(int stack)
{
    if(stack==0){
      if(tot0==0)
        return -1;
      tot0--;
      s0--;
  	  return array[tot0];      
    }
    else{
      if(tot1==arraySize-1)
        return -1;
      tot1++;
      s1--;
  	  return array[tot1];
    }
}

int peek(int stack)
{
    if(stack==0){
      if(tot0==0)
        return -1;
  	  return array[tot0-1];      
    }
    else{
      if(tot1==arraySize-1)
        return -1;
  	  return array[tot1+1];
    }
}
int isEmpty(int stack)
{
  if(stack==0){
    if(tot0==0)
      return 1;      
  }
  else{
    if(tot1==arraySize-1)
      return 1;
  }
  return 0;

}
int main(void)
{
        int N;
        int i;

        int op, val, stack;

        int status;


        scanf("%d",&N);
        init(N);

        while(scanf("%d %d",&op,&stack) != EOF){
                switch(op){
                        case 0: scanf("%d",&val);status=push(stack,val); printf("%d\n",status);break;
                        case 1: status=pop(stack); printf("%d\n",status);break;
                        case 2: status=peek(stack); printf("%d\n",status);break;
                        case 3: status=isEmpty(stack);printf("%d\n",status);break;break;
                }
        }       
        cleanup();
        return 0;
}
