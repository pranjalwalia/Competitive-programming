#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,i,j,f,g;
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {    f=n;
        for(j=n;j>=1;j--,f--){
        if(i<j)
            printf("%d ",f);
        else
            printf("%d ",i);
        }
        g=2;
        for(j=n-1;j>=1;j--,g++){
        if(i<n-j+1)
            printf("%d ",g);
        else
            printf("%d ",i);    
        }
        printf("\n");
    }
    
    for(i=2;i<=n;i++)
    {    f=n;
        for(j=n;j>=1;j--,f--){
        if(i<j)
            printf("%d ",f);
        else
            printf("%d ",i);
        }
        g=2;
        for(j=n-1;j>=1;j--,g++){
        if(i<n-j+1)
            printf("%d ",g);
        else
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
