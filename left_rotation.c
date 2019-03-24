#include stdio.h
#include stdlib.h
void lRotate(int a[],int p, int n)
{
    int i,j;
    int temp=(int)calloc(p,sizeof(int));
    for(i=0;ip;i++)
        (temp+i)=a[i];

    for(i=0;in;i++)
    {   if((i+p)n)
        a[i]=a[i+p];
        else break;
    }
    for(j=0;jp;j++)
    {
        a[i]=(temp+j);
        i++;
    }
    printf(nrotated by %d places,
           p);
      for(i=0;in;i++)
        printf(nn%dt,(a+i));

}
int main()
{
    int p, i,n;
    printf(by how many places do you want to rotaten);
    scanf(%d,&p);
    printf(how many numbers would you like to put in the arrayn);
    scanf(%d,&n);
    int a[n];
    printf(enter the numbersn);
    for(i=0;in;i++)
        scanf(%d,(a+i));

    for(i=0;in;i++)
        printf(%dt,(a+i));

    lRotate(a,p,n);


    return 0;
}
