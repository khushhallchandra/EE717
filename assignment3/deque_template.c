#include<stdio.h>
#include<stdlib.h>

int *array = NULL;
int head, tail, total=0;
int arraySize=0;

char opNames[7][12] = {"push_back","push_front","pop_back","pop_front","back","front","isEmpty"};

void init(int num)
{	arraySize=num;
	//int que[arraySize];
	array=  (int *) malloc (sizeof(int) * (num));
  
  	head = 0;
  	tail=0;
}

void cleanup()
{
  free(array);  
}

int push_back(int val)
{
    if(total==arraySize)
      {
        return 0;
      }
      else
      {
        array[tail]=val;
		tail++;
		tail=tail%arraySize;
        if(total==0){
                          if(head==0)
                	head=arraySize-1;
                else
                  head--;}
        
          
        total++;
      }
       return 1;
}

int push_front(int val)
{

          if(total==arraySize)
          {
                   return 0;
          }
          else
            {	array[head]=val;
                if(head==0)
                	head=arraySize-1;
                else
                	head--;
                if(total==0){
                tail++;
				tail=tail%arraySize;
                }
                total++;
            }

    return 1;
}

int pop_back()
{
	int a;
          if(total==0)
          {
                   return -1;
          }
          else
            {	
            
                if(tail==0)
                	tail=arraySize-1;
                else
                	tail--;
            	a=array[tail];
            if(total==1){
                  head++;
            head=head%arraySize;}
                total--;
            }

    return a;    
}
int pop_front()
{
	int a;
          if(total==0)
          {
                   return -1;
          }
          else
            {
            
			head++;
			head=head%arraySize;
            a=array[head];
            if(total==1){
              if(tail==0)
                tail=arraySize-1;
              else
                tail--;
            }
	        total--;
            }

    return a;    
}

int back()
{
	int a,t;
    if(total==0)
        return -1;          
  else{
    if(tail==0){
      t=arraySize-1;
    }
      else
        t=tail-1;
    a=array[t];}
    return a;    
    
}

int front()
{	int a;
		if(total==0)
          {
            return -1;
          }
          else
            {
            a=array[(head+1)%arraySize];
            }

    return a;   
    
}

int isEmpty()
{
    if(total==0)
    	return 1;
    else
    	return 0;
}


void displayQueue()
{
    int i;
    
    printf("Deque: ");
    for(i=0; i<total; i++){
        printf("%d ",array[(head+i+1)%arraySize]);
    }
    printf("\n");
}

int main(void)
{
        int N;

        int op, val;

        int status;


        scanf("%d",&N);
        init(N);

        while(scanf("%d",&op) != EOF){
                switch(op){
                        case 0: scanf("%d",&val);status=push_back(val); printf("%d\n",status);break;
                        case 1: scanf("%d",&val);status=push_front(val); printf("%d\n",status);break;
                        case 2: status=pop_back(); printf("%d\n",status);break;
                        case 3: status=pop_front(); printf("%d\n",status);break;
                        case 4: status=back(); printf("%d\n",status);break;
                        case 5: status=front(); printf("%d\n",status);break;
                        case 6: status=isEmpty();printf("%d\n",status);break;
                        case 7: displayQueue(); break;
                }
        }       
        displayQueue();
        cleanup();
        return 0;
}
