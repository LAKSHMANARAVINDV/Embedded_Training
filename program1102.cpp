#include <iostream>
#include <string>
using namespace std;

struct Person {
    int age;
    string name;
    string city;
    double height;
};

int main() {
    cout << "=== Accessing Struct Members using Pointer and -> Operator ===" << endl << endl;
    
   
    Person person1;
    person1.age = 28;
    person1.name = "Alice Johnson";
    person1.city = "Boston";
    person1.height = 5.6;
    

    cout << "Method 1: Access using dot operator (.):" << endl;
    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "City: " << person1.city << endl;
    cout << "Height: " << person1.height << " feet" << endl << endl;
    
 
    Person* ptrPerson = &person1;
    cout << "Method 2: Access using pointer and -> operator:" << endl;
    cout << "Name: " << ptrPerson->name << endl;
    cout << "Age: " << ptrPerson->age << endl;
    cout << "City: " << ptrPerson->city << endl;
    cout << "Height: " << ptrPerson->height << " feet" << endl << endl;
    
    
    cout << "Method 3: Access using dereference and dot operator ((*ptr).member):" << endl;
    cout << "Name: " << ptrPerson->name << endl;
    cout << "Age: " << (*ptrPerson).age << endl;
    cout << "City: " << (*ptrPerson).city << endl;
    cout << "Height: " << (*ptrPerson).height << " feet" << endl << endl;
    

    cout << "Modifying members using pointer->member:" << endl;
    ptrPerson->age = 29;
    ptrPerson->city = "New York";
    cout << "Updated Age: " << ptrPerson->age << endl;
    cout << "Updated City: " << ptrPerson->city << endl;
    cout << "Original struct was also modified: " << person1.age << ", " << person1.city << endl << endl;
    

    cout << "Dynamically allocated struct:" << endl;
    Person* dynamicPerson = new Person();
    dynamicPerson->name = "Bob Wilson";
    dynamicPerson->age = 35;
    dynamicPerson->city = "Chicago";
    dynamicPerson->height = 5.9;
    
    cout << "Name: " << dynamicPerson->name << endl;
    cout << "Age: " << dynamicPerson->age << endl;
    cout << "City: " << dynamicPerson->city << endl;
    cout << "Height: " << dynamicPerson->height << " feet" << endl;
    
  
    delete dynamicPerson;
    cout << "\nDynamically allocated memory freed." << endl;
    
    cout << "\n*** Summary of Access Methods: ***" << endl;
    cout << "1. Direct access: variable.member" << endl;
    cout << "2. Pointer access: ptr->member (recommended for readability)" << endl;
    cout << "3. Dereference access: (*ptr).member (less common)" << endl;
    
    return 0;
}
