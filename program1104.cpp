#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    char name[50];
    float gpa;
    int grade;
};

int main() {
    cout << "=== Writing and Reading Student Structs to/from File ===" << endl << endl;
    
    // Step 1: Write multiple Student records to a file
    cout << "Step 1: Writing Student records to file..." << endl;
    
    Student students[5];
    
    // Initialize student data
    students[0] = {1001, "Alice Johnson", 3.85, 12};
    students[1] = {1002, "Bob Smith", 3.65, 11};
    students[2] = {1003, "Carol White", 3.92, 12};
    students[3] = {1004, "David Brown", 3.50, 10};
    students[4] = {1005, "Emma Davis", 3.78, 11};
    
    // Open file for writing in binary mode
    ofstream outFile("Cpp/students.dat", ios::binary);
    
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    
    // Write all student records
    for (int i = 0; i < 5; i++) {
        outFile.write((char*)&students[i], sizeof(Student));
        cout << "Written: ID=" << students[i].id << ", Name=" << students[i].name 
             << ", GPA=" << students[i].gpa << ", Grade=" << students[i].grade << endl;
    }
    
    outFile.close();
    cout << "\nFile closed. " << 5 << " records written successfully." << endl << endl;
    
    // Step 2: Read Student records back from file
    cout << "Step 2: Reading Student records from file..." << endl;
    
    ifstream inFile("Cpp/students.dat", ios::binary);
    
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    
    Student readStudent;
    int recordCount = 0;
    
    cout << "\nRecords read from file:" << endl;
    cout << string(60, '-') << endl;
    
    // Read and display all records
    while (inFile.read((char*)&readStudent, sizeof(Student))) {
        recordCount++;
        cout << "Record " << recordCount << ":" << endl;
        cout << "  ID: " << readStudent.id << endl;
        cout << "  Name: " << readStudent.name << endl;
        cout << "  GPA: " << readStudent.gpa << endl;
        cout << "  Grade: " << readStudent.grade << endl;
        cout << endl;
    }
    
    inFile.close();
    cout << "Total records read: " << recordCount << endl << endl;
    
    // Step 3: Demonstrate random access
    cout << "Step 3: Random access - Reading specific student record..." << endl;
    
    inFile.open("Cpp/students.dat", ios::binary);
    
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    // Read the 3rd student (index 2)
    int recordIndex = 2;
    inFile.seekg(recordIndex * sizeof(Student), ios::beg);
    inFile.read((char*)&readStudent, sizeof(Student));
    
    cout << "Reading student at index " << recordIndex << ":" << endl;
    cout << "  ID: " << readStudent.id << endl;
    cout << "  Name: " << readStudent.name << endl;
    cout << "  GPA: " << readStudent.gpa << endl;
    cout << "  Grade: " << readStudent.grade << endl;
    
    inFile.close();
    
    return 0;
}
