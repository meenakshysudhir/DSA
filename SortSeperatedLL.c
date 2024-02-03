//CREATING A LINKED LIST AND ARRANGING IN ASC ORDER ND CREATING ODD/EVEN LIST
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int Data;
    struct Node* Link;
};
struct Node* GetNode()
{
    return((struct Node*)malloc(sizeof(struct Node)));
}
void insertStart(int D,struct Node** HEADER,int* c)
{
    struct Node** ptr = HEADER;
    struct Node* New = GetNode();
    if(New == NULL)
    {
        printf("Memory Allocation Fault\n");
        return;
    }
    New -> Data = D;
    *(c) = *(c) + 1;
    if((*HEADER) == NULL)
    {
        (*HEADER)  = New;
        New -> Link = NULL;
        printf("Inserted Succesfully !\n");
        
    }
    else
    {
        New -> Link = (*HEADER);
        (*HEADER) = New;
        printf("Inserted Succesfully !\n");

    }
    
}
struct Node* swap(struct Node* ptr1,struct Node* ptr2)
{
    struct Node* temp = ptr2->Link;
    ptr2->Link = ptr1;
    ptr1 -> Link = temp;
    return ptr2;
}
void bubbleSort(struct Node** HEADER, int c)
{
    struct Node** ptr;
    if(HEADER == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    for(int i = 0; i <= c; i++)
    {

        ptr = HEADER;
        int swapped = 0;
        for(int j = 0;j < c-i-1;j++)
        {
            struct Node* p1 = *ptr;
            struct Node* p2 = p1 -> Link;
            if(p1 -> Data > p2 -> Data)
            {
                *ptr = swap(p1,p2);
                swapped = 1;
            }
            ptr = &(*ptr) -> Link;
        }
        if(swapped == 0)
        {
            break;
        }
    }
}

void InsertEnd(struct Node** H,int Data)
{
    struct Node** ptr = H;
    struct Node* New = GetNode();
    New -> Data = Data;
    New -> Link = NULL;
    if((*H) == NULL)
    {
        *H = New;
        return;
    }
    while(*(ptr) != NULL)
    {
        ptr = &(*ptr) -> Link;
    }
    *(ptr) = New;
    return;

}
int main(void)
{
    struct Node*HEADER = NULL;
    int count= 0;
    
    int ch,Data;
    while(1)
    {
        printf("1 - Insert Node at beginning\n2 - Display \n3 - Exit Insertion\nCHOICE : ");
        scanf("%d",&ch);
        if(ch ==1)
        {
            printf("Data : ");
            scanf("%d",&Data);
            insertStart(Data,&HEADER,&count);
        }
        else if(ch == 2)
        {
            printf("Displaying\n");
            struct Node* ptr = HEADER;
            while(ptr != NULL)
            {
                printf("%d\t",ptr -> Data);
                ptr = ptr -> Link;
            }
            printf("\n");
            printf("COUNT : %d",count);
        }
        else if(ch == 3)
        {
            printf("Exiting Insertion\n");
            break;
        }
        else
        {
            printf("Invalid Entry!");
        }
    }
    printf("Sorting the Linked List\n");
    bubbleSort(&HEADER, count);
    printf("Displaying\n");
    struct Node* ptr = HEADER;
    while(ptr != NULL)
    {
        printf("%d\t",ptr -> Data);
        ptr = ptr -> Link;
    }
    printf("\n");
    printf("\n");
    
    //CREATING SEPERATE LINKED LISTS
    struct Node* Even = NULL;
    struct Node* Odd = NULL;
    ptr = HEADER;
    int i = 1;
    while(ptr != NULL)
    {
        if(i%2 == 0)
        {
            InsertEnd(&Even,ptr -> Data);
        }
        else
        {
            InsertEnd(&Odd,ptr->Data);
        }
        ptr = ptr -> Link;
        i++;
    }
    printf("Displaying Even List : \n");
    struct Node* ptrE = Even;
    while(ptrE != NULL)
    {
        printf("%d\t",ptrE -> Data);
        ptrE = ptrE -> Link;
    }
    printf("\n");
    printf("Displaying Odd List : \n");
    struct Node* ptrO = Odd;
    while(ptrO != NULL)
    {
        printf("%d\t",ptrO -> Data);
        ptrO = ptrO -> Link;
    }
    printf("\n");


}