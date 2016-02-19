#include<stdio.h>
int main()
{
	int n,i;
    int a[10000];
    int num[201]={0};
    int mode=num[0];
    int pos=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    //for(i=0;i<n;i++)
    //	printf("%d ",a[i]);
    for(i=0;i<n;i++){
    	if(a[i]>0){
    		num[a[i]]+=1;
    	}
    	else if(a[i]<0){
    		num[100+(-1*a[i])]+=1;
    	}
    	else{
    		num[0]++;
    	}
    }
    for (i = 1; i < 201; i++){
     	if (num[i] > mode){
     		mode  = num[i];
     		pos = i;
     	}
     }
     int count=0;
     int cd=0;
     int b[5];
     for (i = 0; i < 201; i++){
     	if (num[i] == mode){
     		cd++;
          if(i<101)
			b[count++]=i;
          else
               b[count++]=-1*i+100;
     	}
     } 
     int asd[cd];
     if(count==2){
     	for(i=0;i<n;i++){
     		if(b[0]==a[i]|| b[1]==a[i]){
     			pos=a[i];
     			break;
     		}

     	}
     }
	printf("%d",pos);

    return 0;
}