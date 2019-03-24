#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length;
struct ll
{
    char no;
    struct ll *next;
};
void mult(struct ll*, int );

int main()
{
    int n,i;
    char c;
    printf("how many digited no?\n");
    scanf("%d",&n);
    char s[n+1];
    printf("enter the number\n");
    scanf("%s",s);
    puts(s);

    length=strlen(s);

    printf("\n\n");
    struct ll *head=NULL,*temp;
  struct ll *h,*tmp;
  h=(struct ll *)malloc(sizeof(struct ll));
  h->no=s[0];
  h->next=head;
  head=h;   //WE WILL NOT MANIPULATE HEAD AT ANY CONDITION
  for(i=1;i<n;i++)
  {
        tmp=(struct ll *)malloc(sizeof(struct ll));
        tmp->no=s[i];
        tmp->next=NULL;
        h->next=tmp;
        h=h->next;


 }
    h=head;
 while(h!=NULL)
  {printf("%c",h->no);
      h=h->next;
  }
    printf("\nenter the power of 10 to be multiplied\n");
    int  pwr;
    scanf("%d",&pwr);
    mult(head,pwr);
    temp= head;

    while(temp->next!= NULL)
    {
        printf("|%c|->", temp->no);
        temp = temp->next;
    }
    printf("|%c|\n", temp->no);

}


void mult(struct ll *head, int pwr)
{
     int i; char key;
    struct ll *temp, *prev, *p=head;

    int position=1;

      while(p!=NULL)
    {
        if(p->no=='.')break;
        p=p->next;
        position++;
    }

    if(pwr==0)return;
    else if(pwr>0)
    {
        if(length<(position+pwr))
        {
            printf("\nIT IS AN OVERFLOW!!\n\n");
            return;
        }



        for(i=pwr;i>0;i--)
        {
            key = p->no;
            p->no = p->next->no;
            p->next->no = key;

            p = p->next;
        }
        return;

    }

      else
    {
        int absolute;
        absolute = abs(pwr);

        if((head->no=='-' && position==3) || (position==1) ||((head->no=='-') && ((position-absolute)<3)) ||((head->no!='-') && ((position-absolute)<2)) || (absolute>position) )
            {
                printf("\nIT IS AN UNDERFLOW!!\n\n");
                return;
            }

        struct ll *prev;

        for(i=pwr;i<0;i++)
        {
            prev=head;
            p=head->next;

            while((p->no)!= '.')
            {
                p = p->next;
                prev = prev->next;
            }

            key = p->no;
            p->no = prev->no;
            prev->no = key;

        }
    }


return;







}
