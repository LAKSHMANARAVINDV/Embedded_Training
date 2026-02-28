#include<iostream>
using namespace std;

class Device
{
    public:
    Device() {cout<<"Device class created\n";}
};

class Phone : virtual public Device
{
    public:
    Phone() {cout<<"Phone class created\n";}
};

class Camera: virtual public Device
{
    public:
    Camera() {cout<<"Camera class created\n";}
};

class Smartphone : public Phone, public Camera
{
    public:
    Smartphone() {cout<<"Smartphone class created\n";}
};

int main()
{
    Smartphone s;
}