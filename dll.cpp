#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node* prev;
    Node(int val): data(val),next(nullptr),prev(nullptr){};
};

class Dll
{
    private:
    Node* head;
    Node* tail;
    int size;
    public:
    Dll(): head(nullptr),tail(nullptr),size(0){};
    ~Dll()
    {
        Node* curr=head;
        while(curr)
        {
            Node* next=curr->next;
            delete curr;
            curr=next;
        }
    }
    void pushfront(int val)
    {
        Node* node=new Node(val);
        if(!head) head=tail=node;
        else
        {
            node->next=head;
            head->prev=node;
            head=node;
        }
        size++;
    }
    void pushback(int val)
    {
        Node* node=new Node(val);
        if(!tail) head=tail=node;
        else
        {
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
        size++;
    }
    void insertAt(int pos,int val)
    {
        if(!head) pushfront(val);
        if(!tail) pushback(val);
        Node* curr=head;
        for(int i=0;i<pos-1;i++) curr=curr->next;
        Node* node=new Node(val);
        node->next=curr->next;
        node->prev=curr;
        if(curr->next)curr->next->prev=node;
        curr->next=node;
        size++;
    }
    void deletefr()
    {
        if(!head) cout<<"DLL IS EMPTY";
        else
        {
            Node* temp=head;
            head=head->next;
            if(head) head->prev=nullptr;
            else tail=nullptr;
            delete temp;
            size--;
        }
    }
    void deletebk()
    {
        if (!tail) { cout << "List is empty!\n"; return; }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
    }

};

int main()
{
    int i=0;Dll l1;
    do
    {
        int n;
        if(i==0) {cin>>n;l1.pushfront(n);}

    } while (i<5);
    
}