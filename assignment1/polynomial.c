int main()
{
int n,x,i,output=0;
    int a[11]={0};
    int pos=0;
    scanf("%d",&n);
    scanf("%d",&x); 
    for(i=0;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=n;i>=0;i--){
      output=output+(a[n-i]*power(x,i));
    }
    printf("%d",output);                 
return 0;
                     }