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
            // struct Stack* temp = Top;
            Top -> Link = (Top -> Link) -> Link;
            
        }
        else if(ch == 3)
        {
            struct Stack* temp = Top;
            while(temp != 0)
            {
                printf("%d\n",temp -> Data);
                temp = temp -> Link;
            }
        }
    }
}
