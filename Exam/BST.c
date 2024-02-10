/*Write a C Program to create a binary search tree with the following operations - creation, insertion, deletion and
search.*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node* LC;
    struct Node* RC;
};

struct Node* Create(int x)
{
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp -> Data = x;
    temp -> RC = temp -> LC = NULL;
    return temp;
}

struct Node* InsertNode(struct Node* root,int x)
{
    if(root == NULL)
    {
        return Create(x);
    }

    if(x < root -> Data)
    {
        root -> LC = InsertNode(root -> LC, x);
    }
    else if( x > root -> Data)
    {
        root -> RC = InsertNode(root -> RC,x);
    }
    return root;
}

struct Node* succ(struct Node* root)
{
    
    while(root != NULL && root -> LC != NULL)
    {
        root = root -> LC;
    }
    return root;
}
struct Node* DeleteNode(struct Node* root,int x)
{
    if(root == NULL)
    {
        return root;
    }
    if(x < root -> Data)
    {
        root -> LC = DeleteNode(root -> LC,x);
    }
    else if(x > root -> Data)
    {
        root -> RC = DeleteNode(root -> RC,x);
    }
    else
    {
        if(root -> LC == NULL)
        {
            struct Node* temp = root -> RC;
            free(root);
            return temp;
        }
        else if(root -> RC == NULL)
        {
            struct Node* temp = root -> LC;
            free(root);
            return temp;
        }
        struct Node* temp = succ(root -> RC);
        root -> Data = temp -> Data;
        root -> RC = DeleteNode(root -> RC,temp -> Data);
    }
    return root;

}
void SearchKey(struct Node* root,int key)
{
    if(root == NULL)
    {
        printf("Key not found\n");
        return;
    }
    // struct Node* ptr = root;
    if(root -> Data == key)
    {
        printf("Key found");
        return;
    }
    if(key < root -> Data)
    {
        SearchKey(root -> LC,key);
    }
    else
    {
        SearchKey(root -> RC,key);
    }
}
void Inorder(struct Node* root)
{
    struct Node* ptr = root;
    if(ptr == NULL)
    {
        return;
    }
    Inorder(ptr -> LC);
    printf("%d\t",ptr -> Data);
    Inorder(ptr -> RC);
}
int main(void)
{
    int x, ch,key;
    printf("Root : ");
    scanf("%d",&x);
    struct Node* root = Create(x);
    while(1)
    {
        printf("\nEnter 1 to insert node\nEnter 2 to Delete node\nEnter 3 to search\nEnter 4 to Display Inorder\nEnter 5 to exit\nChoice : ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Data : ");
            scanf("%d",&x);
            root = InsertNode(root,x);
            printf("Inserted succesfully !");
        }
        else if(ch == 2)
        {
            //DELETING A NODE
            printf("\nDELETION\nEnter Key : ");
            scanf("%d",&x);
            root = DeleteNode(root,x);
            printf("Deleted successfully\n");
        }
        else if(ch == 3)
        {
            printf("Enter value to search : ");
            scanf("%d",&key);
            SearchKey(root,key);
           
        }
        else if(ch == 4)
        {
            printf("Inoder Traversal of BST : ");
            Inorder(root);
            printf("\n");
        }
        else if(ch == 5)
        {
            printf("Exiting\n");
            break;
        }
        else
        {
            printf("Invalid Entry!\n\n");
        }

    }

}