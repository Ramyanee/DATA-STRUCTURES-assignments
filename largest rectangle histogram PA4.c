#include <stdio.h>
#include <stdlib.h>
int top=-1;
int stack[20];

void maxRectangle(int hist[], int n);
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main()
{
    printf(" _______________________________________________________________________________________________\n");
    printf("|_______________________________________________________________________________________________|\n");
    printf("\n\nA histogram is a polygon composed of a sequence of rectangles aligned at a common base line.\n"
            "The rectangles have equal widths but may have different heights\n\n");
    printf(" _______________________________________________________________________________________________\n");
    printf("|_______________________________________________________________________________________________|\n");

    int n,i;
    printf("\n\nHow many bars do you want to enter in the histogram?\n");
    scanf("%d",&n);

    int hist[n];
    printf("enter the hights of the consecutive bars\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&hist[i]);
    }

    maxRectangle(hist,n);
    return 0;
}

void maxRectangle(int hist[], int n)
{


    int i=0;
    int x1,y1,x2,y2;
    int max_area=0,idx, top_area=0;
    int bar;

    while(i<n)
    {
    bar=stack[top];

            if(isEmpty(top))
            {
                push(i++);

            }
             else if(hist[bar]<hist[i])
            {
                push(i++);

            }
    else
    {
        idx=peek();//index of the bar to compute area
        pop(); //bar idx  to compute the area for

        top_area= hist[idx]*(isEmpty() ? i : i - peek() - 1);

        if(top_area>max_area)
        {
            max_area=top_area;

            if(isEmpty())
                x1=0;
            else
                x1=(peek()+1);

            x2=i;
            y1=y2=hist[idx];

        }
    }
}

       while (isEmpty() == 0)
    {
        idx=peek();
        pop();
        top_area = hist[idx] * (isEmpty() ? i: i - peek() - 1);

        if(top_area>max_area)
        {
            max_area=top_area;
            if(isEmpty())x1=0;else x1=(peek()+1);
            x2=i;
            y1=y2=hist[idx];

        }
    }

    printf("\n\nThe details of the largest rectangle formed by the histogram are:\n");

    printf("||   TOP LEFT:(%d,%d),    TOP RIGHT:(%d,%d),     AREA: %d   ||\n",x1,y1,x2,y2,max_area);
}
void push(int item)
{
    if(isFull())
    {
        printf("stack overflow!!\n");
        return;
    }
    top=top+1;
    stack[top]=item;
}
int pop()
{

    int item;
    if(isEmpty())
    {
        printf("stack underflow!\n");
        exit(1);
    }
    item=stack[top];
    top=top-1;
    return item;

}
int peek()
{
    if(isEmpty())
    {
        printf("stack underflow!");
        exit(1);
    }
    return stack[top];
}
int isEmpty()
{
    if(top==-1) return 1;
    else return 0;
}
int isFull()
{
    if(top==(20-1)) return 1;
    else return 0;
}

void display()
{
    int i;
    printf("stack elements are:\n\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
    printf("\n");
}
