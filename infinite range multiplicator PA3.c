#include <stdio.h>
#include <stdlib.h>
 typedef struct node
 {
     char data;
     struct node* next;
 } linked_list;

int pos1, pos2, flag1, flag2;

//we will take two long numbers in linked list formats and try to manipulate the linked lists to find the product

//declaration of the functions used
void display(linked_list* head);
void insert(linked_list** head, char x);
static void reverse(linked_list** head_ref);
void mult1(linked_list** h1ref, char i);
void add(linked_list** h1ref, linked_list** h2ref, int n);
void multiply(linked_list **href1, linked_list **href2);
void copy ( struct node *q, struct node **s );
void inPut(char num1[], char num2[]);
void outPut(linked_list *head);

// the main driver function
int main()
{
int n;
int i,count=1;

linked_list *head1=NULL;
printf("how many characters do you wanna enter in the first number(\"-\" and \".\" and digits)?\n");
scanf("%d",&n); pos1=n; //so that pos1 reverts back to 0 if no decimal point is there
char num1[n+1];
printf("enter the first number \n");
scanf("%s",num1);
if (num1[0]=='-')flag1=1;
while(count<=n)
{
        i=count-1;
        if(num1[i]=='.') pos1=count;
        if((num1[i]!='.')&& (num1[i]!='-'))insert(&head1,num1[i]);
        count++;
}
pos1=n-pos1; //now pos1 gives the number of digits after '.' in num1
printf("THE MULTIPLICAND IS:\n"); puts(num1);
printf("\n");


count=1;
linked_list *head2=NULL;
printf("how many characters do you wanna enter in the second number( \"-\" and \".\" and digits)?\n");
scanf("%d",&n); pos2=n; //so that pos2 reverts back to 0 if no decimal point is there
char num2[n+1];
printf("enter the second number\n");
scanf("%s",num2);
if(num2[0]=='-')flag2=1;
while(count<=n)
{
        i=count-1;
        if(num2[i]=='.')pos2=count;
        if((num2[i]!='.')&& (num2[i]!='-'))insert(&head2,num2[i]);
        count++;
}
pos2=n-pos2;//now pos2 gives the number of digits after '.' in num2
printf("THE MULTIPLIER IS:\n"); puts(num2);

inPut(num1,num2);

multiply(&head1,&head2);

return 0;
}
// end of main

void insert(linked_list** head, char x)
 {
     linked_list *temp,*p=*head;
     temp=(linked_list*)malloc(sizeof(linked_list));

     if(p==NULL)
 {
     temp->data=x;
     temp->next=NULL;
     *head=temp;
 }

 else
{   while(p->next!=NULL)
    p=p->next;

    //now we have the last element, p->next=NULL

        temp->data=x;
        temp->next=p->next;
        p->next=temp;

 }
 }
void display(linked_list* head)
{
   linked_list* p=head;

    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
}
static void reverse(linked_list** head_ref)
{
   linked_list* prev   = NULL;
   linked_list* current = *head_ref;
   linked_list* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void mult1(linked_list** h1ref, char i)
{
linked_list *p=*h1ref;
int carry=0,a,b;
b=i - '0';
int product, node;
char c,n;
while(p!=NULL)
    {
        a=(p->data) - '0';
        product=(a*b+carry);
        node=product%10;
        carry=product/10;
        n= node + '0';
        p->data=n;
        p=p->next;
    }

    if(carry>0)
{
    c=carry + '0';
    insert(h1ref,c);
}
}

void add(linked_list** h1ref, linked_list** h2ref, int no)
{
    linked_list *p=*h1ref, *q=*h2ref;
    int i, sum=0, node, carry=0;
    char n,c;

    for(i=0;i<no;i++)
    {
        linked_list *temp=(linked_list *)malloc(sizeof(linked_list));
        temp->data='0';
        temp->next=q;
        q=temp;
    }


    while((p!=NULL) || (q!=NULL))
    {
        if(p!=NULL && q!=NULL)
        {
            sum=((p->data - '0')+(q->data - '0')+ carry);
            node= sum%10;
            carry=sum/10;
            n=node + '0';
            p->data=n;
            p=p->next;
            q=q->next;
        }

        else if(p==NULL)
        {
            sum=(q->data - '0')+carry;
            node=sum%10;
            carry=sum/10;
            n=node + '0';
            insert(h1ref,n);
            q=q->next;

        }

    }

if(carry>0)
{       c=carry + '0';
        insert(h1ref,c);
}
}

void copy (linked_list *q,linked_list **s)
{
    if (q!=NULL)
    {
        *s=malloc(sizeof(linked_list));

        (*s)->data=q->data ;
        (*s)->next=NULL ;

        copy(q->next,&((*s)->next));
    }
}

void multiply(linked_list **href1, linked_list **href2)
{
    linked_list *p=*href1, *q=*href2, *copy1=NULL, *copy2=NULL;
    copy(p,&copy1); copy(p,&copy2);
    reverse(&p);
    reverse(&copy1); reverse(&copy2); reverse(&q);
    int i=1;
    mult1(&copy1,q->data);
    q=q->next;
    mult1(&copy2,q->data);
    q=q->next;
    add(&copy1,&copy2,i);
    i++;
 while(q!=NULL)
    {
        copy(p,&copy2);
        mult1(&copy2,q->data);
        add(&copy1,&copy2,i);
        q=q->next;
        i++;

    }


if(flag1!=flag2) insert(&copy1,'-');

int position= pos1+pos2+1;
int count=1;
linked_list *c1=copy1;

if(position>1)
{
    while(count<(position-1))
    {
        c1=c1->next; count++;
    }

    linked_list *temp=(linked_list *)malloc(sizeof(linked_list));
    temp->data='.';
    temp->next=c1->next;
    c1->next=temp;

}

printf("\n\n\nTHE PRODUCT OF THE TWO GIVEN NUMBERS IS:\t");
reverse(&copy1);
display(copy1);
printf("\n\n");

outPut(copy1);
}

void inPut(char num1[], char num2[])
{
    FILE *fileptr=fopen("input.text","w+");
     if(fileptr==NULL)
        {
            printf("\n INPUT file could not be opened!!\n");
            exit(1);
        }
    fputs("this is the input file and following are the inputs given:\n",fileptr);
    fprintf(fileptr, "%s %s", num1, num2);
    printf("\n!!input FILE has been successfully written.!!\n");
    fclose(fileptr);
}
void outPut(linked_list *head)
{
    FILE *fileptr=fopen("output.text","w+");
    char element;
    linked_list *temp = head;
    if(fileptr==NULL)
        {
            printf("\noutput file could not be opened!!\n");
            exit(1);
        }

    fputs("this is the output file and following is the output computed:\n",fileptr);
    while(temp!=NULL)
    {
        element = temp->data;
        fprintf(fileptr, "%c", element);
        temp = temp->next;
    }
    printf("\n!!output FILE has been successfully written.!!\n");
    fclose(fileptr);
}
