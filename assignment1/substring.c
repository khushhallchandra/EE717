#include<stdio.h>
#include <string.h>

int main()
{
	int i,j,pos;
	char str1[19];
	char str2[19];
	char temp[19];
	int found=-1;	
	scanf("%s %s",str1,str2);
	int len1=strlen(str1);
	int len2=strlen(str2);	
	for(i=0;i<(1+len1-len2);i++){
		for(j=i;j<i+len2;j++){
			temp[j-i]=str1[j];
		
		}
		temp[len2]='\0';

		if(strcmp( temp, str2)==0){
			found=i;
			break;
		}
	}
	printf("%d",found);
return 0;
}
