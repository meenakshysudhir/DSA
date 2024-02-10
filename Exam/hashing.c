/*Write a C program to implement a Hash table

(a) Using the Chaining method. Let the size of the hash table
be 10 so that the index varies from 0 to 9.
(b) Using Linear Probing for collision resolution.*/

#include<stdio.h>
#include<stdlib.h>
# define SIZE 10
struct Node
{
    int Key;
    int Val;
    struct Node* Link;
};
int HashFunction(int key)
{
    return key % SIZE;
}
struct Node* Hashtable[10];
void InsertNode(int key,int val)
{
    int ind = HashFunction(key);
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> Key = key;
    newNode -> Val = val;
    newNode -> Link = NULL;

    if(Hashtable[ind] == NULL)
    {
        Hashtable[ind]= newNode;
    }
    else
    {
        struct Node* current = Hashtable[ind];
        while(current -> Link != NULL)
        {
            current = current -> Link;
        }
        current -> Link = newNode;
    }
}
void Display()
{
    for(int i = 0;i < SIZE;i++)
    {
        printf("Index %d : ",i);
        struct Node* temp = Hashtable[i];

        while(temp)
        {
            printf("(%d,%d)  ",temp -> Key,temp -> Val);
            temp = temp -> Link;
        }
        printf("\n");
    }
}
int main(void)
{
    printf("Enter 1 to insert\nEnter 2 to Display\nEnter 3 to exit\n");
    int ch,key,val;
    for(int i = 0; i<10;i++)
    {
        Hashtable[i] = NULL;
    }
    while(1)
    {
        printf("Choice : ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            InsertNode(1, 10);
            InsertNode(11, 20);
            InsertNode(21, 30);
            InsertNode(2, 40);
            InsertNode(12, 50);
            printf("Inserted successfully\n");

        }
        else if(ch == 2)
        {
            printf("Hash Table : \n");
            Display();
        }
        else if(ch == 3)
        {
            printf("Exiting\n");
            break;
        }
        else
        {
            printf("Invalid Entry !\n");
        }
    }
}