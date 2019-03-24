#include <stdio.h>
#include <stdlib.h>
void lRotate(int a[],int p, int n)
{
    int i,j;
    int *temp=(int*)calloc(p,sizeof(int));
    for(i=0;i<p;i++)
        *(temp+i)=a[i];

    for(i=0;i<n;i++)
    {   if((i+p)<n)
        a[i]=a[i+p];
        else break;
    }
    for(j=0;j<p;j++)
    {
        a[i]=*(temp+j);
        i++;
    }
    printf("\nrotated by %d places",
           p);
      for(i=0;i<n;i++)
        printf("\n\n%d\t",*(a+i));

}
int main()
{
    int p, i,n;
    printf("by how many places do you want to rotate?\n");
    scanf("%d",&p);
    printf("how many numbers would you like to put in the array?\n");
    scanf("%d",&n);
    int a[n];
    printf("enter the numbers\n");
    for(i=0;i<n;i++)
        scanf("%d",(a+i));

    for(i=0;i<n;i++)
        printf("%d\t",*(a+i));

    lRotate(a,p,n);


    return 0;
}
