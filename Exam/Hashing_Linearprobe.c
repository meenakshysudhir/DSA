#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int Hashtable[SIZE];
int Hashfun(int key)
{
    return key % SIZE;
}
void insert(int key)
{
    int ind = Hashfun(key);
    while(Hashtable[ind] != -1)
    {
        ind = (ind + 1) % SIZE ;
        
    }
    Hashtable[ind] = key;
}
void Display()
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("Index  %d : %d",i,Hashtable[i]);
        printf("\n");
    }
}
int main(void)
{
    for(int i = 0;i < SIZE;i++)
    {
        Hashtable[i] = -1;
    }
    insert(5);
    insert(15);
    insert(25);
    insert(35);

    Display(Hashtable);
}