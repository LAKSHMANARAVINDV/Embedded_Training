#include<iostream>
using namespace std;

class Order
{
public: 
    struct LineItem
    {
        int id, qty;
    };

    LineItem* l;
    int capacity;
    int count;   

    Order(int);
    ~Order();
    void addLineItem(int,int);
    int totalItems();
    void display();
};

Order::Order(int c):capacity(c),count(0)
{
    cout<<"Order object created\n";
    l = new LineItem[capacity];
}

Order::~Order()
{
    cout<<"Order object destroyed\n";
    delete[] l;
}

void Order::addLineItem(int id,int qty)
{
    if(count >= capacity || capacity == 0)
        cout<<"Illegal operation\n";
    else
    {
        l[count].id = id;
        l[count].qty = qty;
        count++;
    }
}

int Order::totalItems()
{
    int total = 0;
    for(int i = 0; i < count; i++)
        total += l[i].qty;

    return total;
}

void Order::display()
{
    cout << "\nOrder Summary:\n";
    for(int i = 0; i < count; i++)
    {
        cout << "Item ID: " << l[i].id
             << " Quantity: " << l[i].qty << endl;
    }
    cout << "Total Items: " << totalItems() << endl;
}

int main()
{
    Order o1(3);

    o1.addLineItem(101, 2);
    o1.addLineItem(205, 5);
    o1.addLineItem(310, 3);
    o1.addLineItem(22,2);   
    o1.addLineItem(22,2);  

    o1.display();

    return 0;
}