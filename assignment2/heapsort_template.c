#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int * Heap;

void swap(int *A, int a, int b)
{
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

void maxHeapify(Heap h1, int location, int size)
{
	int k=2*location;    
	if(k+1 <= size && h1[k]<h1[k+1]){
   		k = k+1;
	}	
	if(h1[location]<h1[k]){
		swap(h1,location,k);
	}
	location=location*2;
	if(location<=size/2){
		maxHeapify(h1, location, size);
	}
}


int extractMax(Heap h1, int *sizePtr)
{
	int m = h1[1]; //this is the max value, sitiing at the top of the array
	h1[1]=h1[*sizePtr];
	*sizePtr -=1; // size of the array is decreased as one of the element has been extracted
	buildHeap(h1, *sizePtr);// the remaining array is passed to build the heap
	return m;
}
void  buildHeap(Heap h1, int size)
{
	int k;
	for(k=size/2; k!=0; k--)
    {
		maxHeapify(h1, k, size);
	}
}

void printHeap(Heap h1, int size)
{
    int i;
    for(i=1; i<=size-1; i++){
        printf("%d ",h1[i]);
    }
    printf("%d\n",h1[size]);
}

void heapSort(Heap h1, int N)
{
    int num=N;
    int i;

    buildHeap(h1, N);

    for(i=1; i<=num; i++){
        int val = extractMax(h1, &N);
        h1[num-i+1] = val;
    }
    
    
}

void checkSorted(int *A, int N)
{
    int i;
    for(i=1; i<=N-1; i++){
        if(A[i] > A[i+1])
            break;
    }
    if(i != N){
        printf("Output is not sorted");
        exit(1);
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);
    int num=N;
    
    int i;        
    int *h1 = (int *) malloc (sizeof(int) * (N+1));

    for (i=1; i<=N; i++){
        scanf("%d",&h1[i]);
    }

    
    struct timeval start, stop;
    double totaltime;
    
    gettimeofday(&start,NULL);
    heapSort(h1, N);
    gettimeofday(&stop,NULL);
    
    checkSorted(h1,N);
    totaltime = ( stop.tv_sec * 1000000L + stop.tv_usec )
          - ( start.tv_sec * 1000000L + start.tv_usec );
   
    totaltime /= 1000; 
    printf("Size = %d Time taken = %fms\n",N,totaltime);
    return 0;
}