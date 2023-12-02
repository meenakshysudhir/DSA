#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int Data;
    struct Stack* Link;
};

struct Stack* GetNode()
{
    struct Stack* ptr = (struct Stack*)(malloc(sizeof(struct Stack)));
    return ptr;
}
int main(void)
{
    struct Stack* Top = NULL;
    
    while(1)
    {
        printf("1 -> Push Element\n2 -> Pop Element\n3 -> Display Stack\n4 -> Exit\nChoice : ");
        int ch;
        scanf("%d",&ch);
        
        if(ch == 1)
        {
            struct Stack* ptr = GetNode();
            printf("Enter Data to push : ");
            scanf("%d",&(ptr -> Data));
            
            if(Top == NULL)
            {
                Top = ptr;
                ptr -> Link = NULL;
            }
            else
            {
                ptr -> Link = Top;
                Top =  ptr;
            }
        }
        else if(ch == 2)
        {
            if(Top ==  NULL)
            {
                printf("Underflow\n");
            }
            else{
                Top = (Top -> Link) ;
                printf("Top element Popped\n");
            }
            
        }
        else if(ch == 3)
        {
            struct Stack* temp = Top;
            if(temp == NULL)
            {
                printf("Empty Stack\n");
            }
            else{
                while(temp != 0)
                {
                    printf("%d\n",temp -> Data);
                    temp = temp -> Link;
                }
            }
        }
        else if (ch == 4)
        {
            printf("Exited program!\n");
            break;
        }
    }
}
