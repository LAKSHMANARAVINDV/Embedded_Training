#include <iostream>
using namespace std;

// Base class with virtual destructor
class Shape {
public:
    virtual ~Shape() {}  // Virtual destructor
    
    virtual void display() const {
        cout << "This is a Shape" << endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r = 1.0) : radius(r) {}
    
    double getRadius() const {
        return radius;
    }
    
    void display() const override {
        cout << "This is a Circle with radius: " << radius << endl;
    }
};

// Another derived class for demonstration
class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w = 1.0, double h = 1.0) : width(w), height(h) {}
    
    void display() const override {
        cout << "This is a Rectangle with width: " << width << " and height: " << height << endl;
    }
};

int main() {
    cout << "=== dynamic_cast for Safe Downcasting ===" << endl << endl;
    
    // Create derived objects
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    
    // Store in base class pointers
    Shape* shape1 = &circle;
    Shape* shape2 = &rectangle;
    Shape shape3;  // Pure base class object
    
    cout << "Using base class pointers:" << endl;
    shape1->display();
    shape2->display();
    shape3.display();
    cout << endl;
    
    // Safe downcasting using dynamic_cast
    cout << "Safe downcasting using dynamic_cast:" << endl;
    
    // Downcasting shape1 (actually a Circle) to Circle*
    Circle* circlePtr = dynamic_cast<Circle*>(shape1);
    if (circlePtr != nullptr) {
        cout << "Successfully cast to Circle*" << endl;
        cout << "Radius: " << circlePtr->getRadius() << endl;
    } else {
        cout << "Failed to cast to Circle*" << endl;
    }
    cout << endl;
    
    // Attempting to downcast shape2 (Rectangle) to Circle* - will fail safely
    Circle* wrongCirclePtr = dynamic_cast<Circle*>(shape2);
    if (wrongCirclePtr != nullptr) {
        cout << "Successfully cast shape2 to Circle*" << endl;
    } else {
        cout << "Failed to cast shape2 to Circle* (as expected - it's a Rectangle!)" << endl;
    }
    cout << endl;
    
    // Downcasting shape2 to Rectangle* - will succeed
    Rectangle* rectanglePtr = dynamic_cast<Rectangle*>(shape2);
    if (rectanglePtr != nullptr) {
        cout << "Successfully cast shape2 to Rectangle*" << endl;
    } else {
        cout << "Failed to cast shape2 to Rectangle*" << endl;
    }
    cout << endl;
    
    // Attempting to downcast pure Shape object to Circle* - will fail
    Shape* shapePtr = &shape3;
    Circle* shapeAsCircle = dynamic_cast<Circle*>(shapePtr);
    if (shapeAsCircle != nullptr) {
        cout << "Successfully cast Shape to Circle*" << endl;
    } else {
        cout << "Failed to cast pure Shape object to Circle* (as expected!)" << endl;
    }
    cout << endl;
    
    cout << "*** Benefits of dynamic_cast: ***" << endl;
    cout << "1. Returns nullptr if downcasting fails (safe)" << endl;
    cout << "2. Returns the correct pointer if downcasting succeeds" << endl;
    cout << "3. Requires virtual functions in base class" << endl;
    cout << "4. Works at runtime (RTTI - Run-Time Type Information)" << endl;
    cout << "5. Prevents undefined behavior from incorrect casts" << endl;
    
    return 0;
}
