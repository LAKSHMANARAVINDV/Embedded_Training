#include <iostream>
#include <string>
using namespace std;

// Nested struct Address inside Employee
struct Address {
    string street;
    string city;
    string state;
    string zipCode;
};

struct Employee {
    int id;
    string name;
    string department;
    double salary;
    Address address;  // Nested struct
};

int main() {
    cout << "=== Nested Struct: Address inside Employee ===" << endl << endl;
    
    // Create an Employee with Address
    Employee emp1;
    emp1.id = 101;
    emp1.name = "John Doe";
    emp1.department = "Engineering";
    emp1.salary = 75000.00;
    
    // Initialize nested Address struct
    emp1.address.street = "123 Main Street";
    emp1.address.city = "New York";
    emp1.address.state = "NY";
    emp1.address.zipCode = "10001";
    
    // Display complete employee details
    cout << "Employee Details:" << endl;
    cout << "=================" << endl;
    cout << "ID: " << emp1.id << endl;
    cout << "Name: " << emp1.name << endl;
    cout << "Department: " << emp1.department << endl;
    cout << "Salary: $" << emp1.salary << endl;
    cout << "\nAddress Details:" << endl;
    cout << "Street: " << emp1.address.street << endl;
    cout << "City: " << emp1.address.city << endl;
    cout << "State: " << emp1.address.state << endl;
    cout << "Zip Code: " << emp1.address.zipCode << endl;
    
    cout << "\n" << string(50, '-') << endl;
    
    // Create another Employee
    Employee emp2;
    emp2.id = 102;
    emp2.name = "Jane Smith";
    emp2.department = "Marketing";
    emp2.salary = 65000.00;
    
    emp2.address.street = "456 Oak Avenue";
    emp2.address.city = "Los Angeles";
    emp2.address.state = "CA";
    emp2.address.zipCode = "90001";
    
    cout << "\nEmployee 2 Details:" << endl;
    cout << "=================" << endl;
    cout << "ID: " << emp2.id << endl;
    cout << "Name: " << emp2.name << endl;
    cout << "Department: " << emp2.department << endl;
    cout << "Salary: $" << emp2.salary << endl;
    cout << "\nAddress:" << endl;
    cout << emp2.address.street << ", " << emp2.address.city 
         << ", " << emp2.address.state << " " << emp2.address.zipCode << endl;
    
    return 0;
}
