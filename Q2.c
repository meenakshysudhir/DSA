#include<stdio.h>
#include<stdlib.h>

struct Poly
{
    int coef;
    int expon;
    struct Poly* link;
};

struct Poly* GetNode()
{
    struct Poly* new_node = (struct Poly*)malloc(sizeof(struct Poly));
    return new_node;
}
int main(void)
{
    struct Poly* Header1 =NULL;
    struct Poly* Header2 = NULL;
    int d1,d2;
    printf("Polynomial A\nNo. of terms of Polynomial A : ");
    scanf("%d",&d1);
    while(d1 > 0)
    {
        struct Poly* ptr = Header1;
        struct Poly* new =GetNode();
        printf("Coefficient and Exponenet: ");
        scanf("%d%d", &(new -> coef),&(new -> expon));
        new -> link = NULL;
        if(Header1 == NULL)
        {
            Header1 = new;
        }
        else
        {
            while(ptr -> link != NULL)
            {
                // PreviousNode = ptr;
                ptr = ptr -> link;
            }
            ptr -> link = new;
        }
        d1--;

    }
    printf("\n");
    printf("Polynomial B\n");
    printf("No.of terms of Polynomial B : ");
    scanf("%d",&d2);
    while(d2 > 0)
    {
       
        struct Poly* ptr = Header2;
        struct Poly* new = GetNode();
        printf("coefficient and exponenet: ");
        scanf("%d%d", &(new -> coef),&(new -> expon));
        new -> link = NULL;
        if(Header2 == NULL)
        {
            Header2 = new;
        }
        else
        {
            while(ptr -> link != NULL)
            {
                // PreviousNode = ptr;
                ptr = ptr -> link;
            }
            ptr -> link = new;
        }
        d2--;
 
    }
    printf("displaying\n");
    struct Poly* ptrA = Header1;
    struct Poly* ptrB =Header2;
    printf("polynomial A :\n");
    while(ptrA != NULL)
    {
        printf("%dx^%d ",ptrA -> coef ,ptrA -> expon);
        ptrA = ptrA -> link;
        if(ptrA != NULL)
        {
            printf("+");
        }
    }
    printf("\nPolynomial B :\n");
    while(ptrB != NULL)
    {
        printf("%dx^%d ",ptrB -> coef ,ptrB -> expon);
        ptrB = ptrB -> link;
        if(ptrB != NULL)
        {
            printf("+");
        }
    }

    //SUM OF POLYNOMIALS
    struct Poly* ptrA2 = Header1;
    struct Poly* ptrB2 = Header2;
    struct Poly* ResHeader = NULL;  
    struct Poly* temp = ResHeader;
    while(ptrA2 != NULL && ptrB2 != NULL)
    {
        if(ptrA2 -> expon == ptrB2 -> expon)
        {
            struct Poly* Res = GetNode();
            Res -> coef =(( ptrA2 -> coef) + ( ptrB2 -> coef));
            Res -> expon = ptrA2 -> expon;
            // printf("%d  %d\n",Res -> coef, Res -> expon);
            if(ResHeader == NULL)
            {
                ResHeader = Res;
                Res -> link = NULL;
                temp=ResHeader;
            }
            else
            {
                while(temp -> link != NULL)
                {
                    temp = temp -> link;
                }
                temp -> link = Res;
                Res -> link = NULL;              
            }
            ptrA2 = ptrA2 -> link;
            ptrB2 = ptrB2 -> link;
        }
        else if(ptrA2 -> expon > ptrB2 -> expon)
        {
            struct Poly* Res = GetNode();
            Res -> coef = ptrA2 -> coef;
            Res -> expon = ptrA2 -> expon;
            // temp = ResHeader;
            if(ResHeader == NULL)
            {
                ResHeader = Res;
                Res -> link = NULL;
                temp = ResHeader;
            }
            else
            {
                while(temp -> link != NULL)
                {
                    temp = temp -> link;
                }
                temp -> link = Res;
                Res -> link = NULL;
            }
            ptrA2 = ptrA2 -> link;
        }
        else if(ptrB2 -> expon > ptrA2 -> expon)
        {
            struct Poly* Res = GetNode();
            Res -> coef = ptrB2 -> coef;
            Res -> expon = ptrB2 -> expon;
            
            if(ResHeader == NULL)
            {
                ResHeader = Res;
                Res -> link = NULL;
                temp = ResHeader;
                
            }
            else
            {
                while(temp -> link != NULL)
                {
                    temp = temp -> link;
                }
                temp -> link = Res;
                Res -> link = NULL;
            }
            ptrB2 = ptrB2 -> link;
        }
    }
    if(ptrA2 == NULL &&  ptrB2 != NULL)
    {
        // struct Poly*
        temp = ResHeader;
        while(temp -> link != NULL)
        {
            temp = temp -> link;
        }
        while(ptrB != NULL)
        {
            struct Poly* Res = GetNode();
            Res -> coef = ptrB2 -> coef;
            Res -> expon = ptrB2 -> expon;
            temp -> link = Res;
            Res -> link = NULL;
            temp = temp -> link;
            ptrB2 = ptrB2 -> link;
        }
    }
    if(ptrB2 == NULL &&  ptrA2 != NULL)
    {
        // struct Poly*
        temp = ResHeader;
        while(temp != NULL)
        {
            temp = temp -> link;
        }
        while(ptrA2 != NULL)
        {
            struct Poly* Res = GetNode();
            Res -> coef = ptrA2 -> coef;
            Res -> expon = ptrA2 -> expon;
            temp -> link = Res;
            Res -> link = NULL;
            temp = temp -> link;
            ptrA2 = ptrA2 -> link;
        }
    }
    printf("\nRESULT:\n");
    temp = ResHeader;
    while(temp != NULL)
    {
        printf("%dx^%d ",temp -> coef ,temp -> expon);
        temp = temp -> link;
        if(temp != NULL)
        {
            printf("+");
        }
    }
    
    //POLYNOMIAL MULTIPLICATION
    ptrA = Header1;
    ptrB = Header2;
    struct Poly* Mult = NULL;
    // temp = Mult;
    while(ptrA != NULL)
    {
        ptrB = Header2;
        while(ptrB != NULL)
        {
            struct Poly* new = GetNode();
            new -> coef = (ptrA -> coef * ptrB -> coef);
            new -> expon = ptrA -> expon + ptrB -> expon;
            new -> link = NULL;
            if(Mult == NULL)
            {
                Mult = new;
                temp = Mult;
                
            }
            else
            {
                while(temp -> link != NULL)
                {
                    temp = temp -> link;
                }
                temp -> link = new;
            }
            ptrB = ptrB -> link;
        }
        ptrA = ptrA -> link;
    }
    //DISPLAYING PRODUCT;
    temp = Mult;
    printf("\nProduct of Polynomials : \n");
    while(temp != NULL)
    {
        printf("%dx^%d ",temp -> coef ,temp -> expon);
        temp = temp -> link;
        if(temp != NULL)
        {
            printf("+ ");
        }
    }
}





