#include<iostream>
using namespace std;

class Media
{
public:
    virtual void play()
    {
        cout << "Playing generic media" << endl;
    }
};

class Audio : public Media
{
public:
    void play() override
    {
        cout << "Playing audio file" << endl;
    }
};

class Video : public Media
{
public:
    void play() override
    {
        cout << "Playing video file" << endl;
    }
};

int main()
{
    Media* ptr;

    Audio a;
    Video v;

    ptr = &a;
    ptr->play();  
    ptr = &v;
    ptr->play();   

    return 0;
}