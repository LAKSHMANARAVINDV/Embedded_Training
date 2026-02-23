#include<stdio.h>

typedef struct
{
    int price;
    int discount;
}Product;


int Dis(Product p)
{
    return (p.price-(p.price*0.01*p.discount));
}

void update(Product* p,int n)
{
    p->price=n;
    return;
}

int main()
{
    Product a ={1200,10};
    printf("Discount: %d\n",Dis(a));
    update(&a,2000);
    printf("Discount: %d",Dis(a));
    return 0;
}