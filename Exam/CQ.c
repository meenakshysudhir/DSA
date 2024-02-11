#include <stdio.h>
//CQ using arrays
#define SIZE 5


int rear = -1,front = -1;

int CQ[SIZE] ;
void insertRear(int x)
{
    if((rear + 1) % SIZE == front)
    {
        printf("CQ is Full\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1 )% SIZE;
    }
    CQ[rear] = x;
    return;
    
}
void  deleteFront()
{
    if(front == -1 || rear == -1)
    {
        printf("CQ is empty\n");
        return;
    }
    if(front == rear)
    {
        front = -1;
        rear = -1;  
    }
    else
    {
        front = (front + 1) % SIZE;
    }
    return ;
}

void Display()
{
    if(front == -1 && rear == -1)
    {
        printf("Empty Queue\n");
        return;
    }
    int i = front;
    do
    {
        printf("%d\t", CQ[i]);
        i = (i + 1) % SIZE;
    } while (i != (rear + 1) % SIZE);

    printf("\n");
}

int main(void)
{
    insertRear(2);
    insertRear(-1);
    insertRear(5);
    insertRear(6);
    insertRear(7);
    Display();
    deleteFront();
    Display();

}