/*Write a C program to create a structure Employee with fields EmpId,Name and Salary. Name should contain first name, middle name and
last name. Store the details of n employees, dynamically allocating memory for the same. Write a function to implement Linear Search
to search for a particular employee, given the EmpId.*/
#include <stdio.h>
#include <stdlib.h>

struct Employee 
{
    int EmpId;
    char Name[100];
    int Salary;
};
void SearchId(struct Employee* l,int id,int n)
{
    int fl = 0;
    for(int i = 0;i < n;i++)
    {
        if(l[i].EmpId == id)
        {
            printf("EmpId found\n");
            fl = 1;
            break;
            return;
        }
    }
    if(fl == 0)
    {
        printf("EmpId not found\n");
        return;
    }
}
int main(void)
{
    printf("Number of employees : ");
    int n,Id;
    scanf("%d",&n);
    struct Employee* List = (struct Employee*)(malloc(n*(sizeof(struct Employee))));
    for(int i = 0;i<n;i++)
    {
        printf("Employee Id : ");
        scanf("%d",&List[i].EmpId);
        printf("Name : ");
        scanf("%s",List[i].Name);
        printf("Salary : ");
        scanf("%d",&List[i].Salary);
        printf("\n");
    }
    printf("Enter the id you want to search: \n");
    scanf("%d",&Id);
    SearchId(List,Id,n);
}