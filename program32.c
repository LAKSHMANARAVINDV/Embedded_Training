#include<stdio.h>

typedef struct {
    char cust_name[20];
    int cust_id;
} Customer;

typedef struct {
    char item_name[10];
    int iteam_id;
} Item;

typedef struct {
    int order_id;
    Item i;
    Customer c;
} Order;

void print(Order*);
int main()
{
    Order o = {2,{"Lays",27},{"Arun",10}};
    print(&o);
}

void print(Order* a)
{
    printf("Order id: %d\nItem name: %s\nItem id: %d\nCustomer name: %s\nCustomer id: %d",a->order_id,a->i.item_name,a->i.iteam_id,a->c.cust_name,a->c.cust_name);
}