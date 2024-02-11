#include<stdio.h>
#define SIZE 10
struct Element 
{
    int data;
    int pri;
}pq[100];
int size = -1;
void insertPQ(int x,int pr)
{
    if(size == SIZE -1)
    {
        printf("Overflow\n");
        return;
    }
    struct Element Node;
    Node.data = x;
    Node.pri = pr;
    int i;
    for(i = size; i >=0 && pq[i].pri > pr;i--)
    {
        pq[i+1] = pq[i];
    }
    pq[i+1] = Node;
    size++;
    for(int k = 1;k <= size;k++)
    {
        struct Element temp = pq[k];
        int z = k -1;
        while(z >= 0 && pq[z].pri> temp.pri)
        {
            pq[z+1] = pq[k];
        }
        pq[z+1] =temp;
    }
    return;
}
void deletePQ()
{
    if(size == -1)
    {
        printf("PQ is empty\n");
        return;
    }
    printf("Deleted Element : %d with priority %d",pq[size].data,pq[size].pri);
    size--; 
    return;
}
void display()
{
    if(size == -1)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Element\tPriority\n");
    for(int i = 0; i <= size;i++)
    {
        printf("%d\t%d\n",pq[i].data,pq[i].pri);
    }
    return;
}
int main(void)
{
    printf("1 for inserting\n2 for deleting\n3 for displaying\n");
    int ch,x,p;
    while(1)
    {
        printf("Choice : ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Data and priority: ");
            scanf("%d%d",&x,&p);
            insertPQ(x,p);
        }
        else if(ch == 2)
        {
            deletePQ();
        }
        else if(ch == 3)
        {
            display();
        }
        else if(ch ==4)
        {
            printf("Exited\n");
            break;
        }
        else
        {
            printf("Invalid entry!\n");
        }
    }
}