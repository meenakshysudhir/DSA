/*Write a menu driven C Program to create a binary tree
using linked list with the following operations
1. Insert a new node
2. Inorder traversal
3. Preorder traversal
4. Postorder traversal
5. Delete a node*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int Data;
    struct Node* LC;
    struct Node* RC;
};
struct Node* Create(int x)
{
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp -> Data  = x;      
    temp -> RC = temp -> LC = NULL;
    return temp;
}

void InsertNode(struct Node* root,int x,int key)
{
    if(root == NULL)
    {
        return;
    }
    InsertNode(root -> LC,x,key);
    if(root -> Data == key)
    {
        if(root -> LC == NULL || root  -> RC == NULL)
        {
            struct Node* temp = Create(x);
            if(root -> LC == NULL)
            {
                root -> LC = temp;
            }
            else{
                root -> RC = temp;
            }
            printf("Inserted successfully\n");
        }
        return;
    }
    InsertNode(root -> RC,x,key);
}
void Inorder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root -> LC);
    printf("%d\t",root -> Data);
    Inorder(root -> RC);
}
void Preorder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\t",root->Data);
    Preorder(root -> LC);
    Preorder(root -> RC);
}
void Postorder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    Postorder(root -> LC);
    Postorder(root -> RC);
    printf("%d\t",root->Data);

}

void DeleteNode(struct Node* root,int key,struct Node* par)
{
    if(root == NULL)
    {
        return;
    }
    if(root -> Data == key)
    {
        if(root -> LC == NULL && root -> RC == NULL)    //LEAF NODE
        {
            if(par -> LC == root)
            {
                par -> LC = NULL;
                free(root);
                printf("Node deleted\n");
                return;
            }
            else if(par -> RC == root)
            {
                par -> RC = NULL;
                free(root);
                printf("Node deleted\n");
                return;
            }
        }
    }
    DeleteNode(root -> LC,key,root);
    DeleteNode(root -> RC,key,root);
    
}
int main(void)
{
    int x,par,ch,key;
    printf("Root : ");
    scanf("%d",&x);
    struct Node* root = Create(x);
    while(1)
    {
        printf("Enter 1 to insert node\nEnter 2 for Inorder Traversal\nEnter 3 for Preorder Traversal\nEnter 4 for Postorder Traversal\nEnter 5 to delete Node\nEnter 6 to exit\nChoice : ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Data : ");
            scanf("%d",&x);
            printf("Parent : ");
            scanf("%d",&par);
            InsertNode(root,x,par);
        }
        else if(ch == 2)
        {
            printf("Inorder Traversal : ");
            Inorder(root);
        }
        else if(ch == 3)
        {
            printf("Preorder Traversal : ");
            Preorder(root);
        }
        else if(ch == 4)
        {
            printf("PostOrder Traversal : ");
            Postorder(root);
        }
        else if(ch == 5)
        {
            printf("Enter Node to be deleted : ");
            scanf("%d",&key);
            DeleteNode(root,key,NULL);

        }
        else if(ch == 6)
        {
            printf("Exiting\n");
            break;
        }
        else
        {
            printf("Invalid Entry!\n");
        }

    }
}

    