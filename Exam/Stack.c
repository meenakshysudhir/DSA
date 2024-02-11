#include<stdio.h>
#define SIZE 5

int Top = -1;
void Push(int A[],int x)
{
    if(Top == SIZE - 1)
    {
        printf("Overflow \n");
        return;
    }
    Top++;
    A[Top] = x;
    printf("Pushed!\n");
    return;
}
void Pop(int A[])
{
    if(Top == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Popped : %d",A[Top]);
    Top--;
}
void Display(int S[])
{
    int i = Top;
    printf("Stack : ");
    while(i != -1)
    {
        printf("%d\t",S[i--]);
    }
}


int main(void)
{
    int ch;
    int x;
    int S[SIZE];
    printf("Enter 1 to push\nEnter 2 to Pop\nEnter 3 to Display\n");
    while(1)
    {
        printf("Choice : ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Element : ");
            scanf("%d",&x);
            Push(S,x);
        }
        else if(ch == 2)
        {
            Pop(S);
        }
        else if(ch == 3)
        {
            Display(S);
        }
        else
        {
            printf("Exited\n");
            break;
        }
    }
}