 #include<iostream>
using namespace  std;

// Overloading an operator to add two complex numbers

class Complex
{
public:
float real,imag;
Complex(int a=0,int b=0):real(a),imag(b) {};
Complex operator+ (const Complex&);
void show();
};

Complex Complex::operator+ (const Complex& c)
{
return Complex(real+c.real, imag+c.imag);
}

void Complex::show()
{
cout<<real<<"+i"<<imag<<endl;
}

int main()
{
Complex a(10,5),b(10,1);
Complex c=a+b;
c.show();
return 0;
}
