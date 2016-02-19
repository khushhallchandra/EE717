#include<stdio.h>
int main()
{
	int num;
	int root=0;
	int sum=0;
    scanf("%d",&num);
    sum=num;
    while(sum>9){
    	num=sum;
    	sum=0;
		while(num>0){
			sum=sum+num%10;
			num=num/10;
		}
	}
	printf("%d",sum);	
	return 0;
}