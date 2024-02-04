//Reverse a singly linked list without traversing it twice
#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int Data;
    struct Node* Link;
};
struct Node* GetNode()
{
    return((struct Node*)(malloc(sizeof(struct Node))));
}
void InsertEnd(struct Node** Header,int Data)
{
    struct Node** ptr = Header;
    struct Node* New = GetNode();
    if(New == NULL)
    {
        printf("Error in Memory Allocation !\n");
        return;
    }
    New -> Data = Data;
    New -> Link = NULL;
    if(*Header == NULL)
    {
        *Header = New;
        return;
    }
    while(*(ptr) != NULL)
    {
        ptr = &(*ptr) -> Link;
    }
    *(ptr) = New;
}
int main(void)
{
    int ch;
    struct Node* Header = NULL;
    while(1)
    {
        printf("Enter 1 to Insert at the end\nEnter 2 to Display\nEnter 3 to reverse\nEnter 4 to Exit\nChoice : ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Data : ");
            int Data;
            scanf("%d",&Data);
            InsertEnd(&Header,Data);
        }
        else if(ch == 2)
        {
            printf("\nDISPLAYING\n");
            struct Node* ptr = Header;
            while(ptr != NULL)
            {
                printf("%d\t",ptr -> Data);
                ptr = ptr -> Link;
            }
            printf("\n");

        }
        else if(ch == 3)
        {
            struct Node* p1 = Header;
            struct Node* p2 = p1 -> Link;
            p1 -> Link = NULL;
            while(p2 != NULL)
            {
                struct Node* temp = p2 ->Link;
                p2 -> Link = p1;
                p1 = p2;
                p2 = temp;      
            }
            Header = p1;
            printf("REVERSED\n");
        }
        else if(ch == 4)
        {
            printf("Breaking from the loop \n");
            break;
        }
        else
        {
            printf("Invalid Entry!\n");
        }
    } 
}