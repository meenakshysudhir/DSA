#include <stdio.h>
#define SIZE 5
int CQ[SIZE];
int front = -1, rear = -1;
void insertRear(int x)
{
    if(front==(rear + 1) % SIZE)
    {
        printf("Overflow\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }
    CQ[rear] = x;
    return;
}
void deleteFront()
{
    if(front == -1 || rear == -1)
    {
        printf("Underflow\n");
        return;
    }
    if(front ==  rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
    return;
}
void insertFront(int x)
{
    if(((front == 0)  && (rear == SIZE - 1))|| (front == rear + 1))
    {
        printf("Overflow\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
    {
        front = SIZE -1;
    }
    else
    {
        front--;
    }
    CQ[front] = x;
}
void deleteRear()
{
    if(front == -1 || rear == -1)
    {
        printf("Underflow\n");
        return;
    }
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(rear == 0)
    {
        rear = SIZE -1;
    }
    else{
        rear--;
    }
    return;
}
void Display()
{
    printf("Deque : ");
    int i = front;
    if(front == -1 || rear == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    do
    {
        printf("%d\t",CQ[i]);
        i = (i+1)%SIZE;
    } while (i != (rear + 1)% SIZE);
    printf("\n");
    
}
int main(void)
{
    insertFront(2);
    insertFront(5);
    insertRear(-1);
    insertRear(0);
    insertFront(7);
    insertFront(4);
    Display();
    deleteFront();
    deleteRear();
    deleteFront();
    Display();
}