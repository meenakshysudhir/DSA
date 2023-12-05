#include<stdio.h>
struct poly
{
    int coef;
    int expon;
};
int main(void)
{
    int n1,n2;
    struct poly polyA[100];
    struct poly polyB[100];
    struct poly res[100];
    printf("Polynomial A\nNumber of terms : ");
    scanf("%d",&n1);
    for(int i = 0; i < n1; i++)
    {
        printf("Coefficients : ");
        scanf("%d",&polyA[i].coef);
        printf("Exponent : ");
        scanf("%d",&polyA[i].expon);
    }
    
    printf("Polynomial B\nEnter the number of terms : ");
    scanf("%d",&n2);
    for(int i = 0; i < n2; i++)
    {
        printf("Coefficients : ");
        scanf("%d",&polyB[i].coef);
        printf("Exponent : ");
        scanf("%d",&polyB[i].expon);
    }
    int num1 = n1;
    int num2 = n2;
    //DISPLAYING POLYA
    while(num1 > 0)
    {
        printf("%dx^%d ",polyA[n1-num1].coef,polyA[n1-num1].expon);
        num1--;
        if(num1 != 0)
        {
            printf("+");
        }
    }
    printf("\n");
    //DISPLAYING POLYB
    while(num2 > 0)
    {
        printf("%dx^%d ",polyB[n2-num2].coef,polyB[n2-num2].expon);
        num2--;
        if(num2 != 0)
        {
            printf("+");
        }
    }
    printf("\n");

    int i = 0;
    int j = 0;
    int k;
    k = 0;
    while(i <n1 && j < n2)
    {
        if(polyA[i].expon == polyB[j].expon)
        {
            res[k].expon = polyA[i].expon;
            res[k].coef = polyA[i].coef + polyB[j].coef ;
            i++;
            j++;
            k++;
        }
        else if(polyA[i].expon > polyB[j].expon)
        {
            res[k].expon = polyA[i].expon;
            res[k].coef = polyA[i].coef;
            i++;
            k++;
        }
        else if (polyB[j].expon > polyA[i].expon)
        {
            res[k].expon = polyB[j].expon;
            res[k].coef = polyB[j].coef ;
            j++;
            k++;
        }
        
        
    }
    while( i < n1)
    {
        res[k].expon = polyA[i].expon;
        res[k].coef = polyA[i].coef;
        i++;
        k++;
    }
    while(j < n2)
    {
        res[k].expon = polyB[j].expon;
        res[k].coef = polyB[j].coef;
        j++;
        k++;
    }
    
    int num = k;
    //DISPLAYING RESULTANT POLY
    // while(num > 0)
    // {
    //     printf("Hello");
    //     printf("%dx^%d ",res[num].coef,res[num].expon);
    //     num--;
    //     if(num != 0)
    //     {
    //         printf("+");
    //     }
    // }
    for(int i = 0;i<num;i++)
    {
        printf("%dx^%d",res[i].coef,res[i].expon);
        if(i != num -1)
        {
            printf(" + ");
        }
    }
}
