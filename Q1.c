//LINKED LIST
/*a. Display
b. Insert at Beginning
c. Insert at End
d. Insert at a specified Position
e. Delete from Beginning
f. Delete from End
g. Delete from a specified Position*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* Link;
};


struct Node* GetNode()
{
    struct Node* new_ptr = (struct Node*) malloc(100*sizeof(struct Node));
}

int CheckPointer(struct Node* ptr)
{
    if(ptr == NULL)
    {
        printf("Error allocating Memory !!\n");
        return 0;
    }
    return 1;
}
int main()
{
    int n ,Data;
    struct Node* Header = NULL;
    struct Node* ptr;
    
    while(1)
    {
        printf("\nLINKED LIST\n1 -> Insert at beginning\n2 -> Insert at end\n3 -> Insert at a specific position\n");
        printf("4 -> Delete from Beginning\n5 -> Delete from End\n6 -> Delete from a specific position\n7 -> Display\n8 -> Exit\nChoice : ");
        int ch;
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Data to be inserted at the beginning : ");
            struct Node* ptr = GetNode();
            if(CheckPointer(ptr) == 0){break;}
            scanf("%d", &Data);
            ptr -> data = Data;
            ptr -> Link = Header;
            Header = ptr;
            printf("\nData inserted at the beginning\n");

        }
        else if(ch == 2)
        {
            if(Header == NULL)
            {
                printf("No Node in the beginning\n");
                break;
            }
            printf("Data to be inserted at the end : ");
            scanf("%d",&Data);
            struct Node* ptr = Header;
            while(ptr -> Link != NULL)
            {
                ptr = ptr -> Link;
                
            }
            struct Node* ptr1 = GetNode();
            
            if(CheckPointer(ptr1) == 0)
            {
                printf("YES");
                break;
                
            }
            ptr -> Link = ptr1;
            ptr1 -> data = Data;
            ptr1 -> Link = NULL;
            printf("\nData inserted at the End\n");
        }
        else if(ch == 3)
        {
            printf("Enter the key value after which data is to be inserted : ");
            int key;
            scanf("%d",&key);
            struct Node* ptr = Header;
            while(ptr != NULL)
            {
                if(ptr -> data == key)
                {
                    struct Node* ptr1 = GetNode();
                    if(CheckPointer(ptr1) == 0){break;}
                    printf("Enter the new data : ");
                    scanf("%d",&Data);
                    ptr1 -> data = Data;
                    ptr1 -> Link = ptr -> Link;
                    ptr -> Link = ptr1;
                }
                ptr = ptr -> Link;
            }
            printf("\nData Inserted\n");
        }
        else if(ch == 4)
        {
            if(Header == NULL)
            {
                printf("No Nodes\n");
            }
            else
            {
                struct Node* ptr = Header;
                Header = ptr -> Link;
                printf("\nFirst Node Deleted\n");
            }
        }
        else if(ch == 5)
        {
            struct Node* ptr1;
            ptr = Header;
            while(ptr -> Link != NULL)
            {
                ptr1 = ptr;
                ptr = ptr -> Link;
            }
            ptr1 -> Link = NULL;
            free(ptr);
            printf("\nData deleted from the End\n");
        }
        else if(ch == 6)
        {
            struct Node* ptr1;
            ptr = Header;
            int key;
            printf("Enter the key value to delete : \n");
            scanf("%d",&key);
            while(ptr -> Link != NULL)
            {
                ptr1 = ptr;
                ptr = ptr -> Link;
                if(ptr -> data == key)
                {
                    ptr1 -> Link = ptr -> Link;
                    free(ptr);
                }
            }
            printf("Key %d deleted\n",key);
        }
        else if(ch == 7)
        {
            printf("\nDISPLAYING DATA :\n");
            struct Node* ptr = Header;
            printf("DATA : \n");
            while(ptr != NULL)
            {
                printf("%d\t", ptr -> data);
                ptr = ptr -> Link;
            }
        }
        else if(ch == 8)
        {
            printf("\nExiting the program !\n"); 
            break;
        }
    }
}
        



