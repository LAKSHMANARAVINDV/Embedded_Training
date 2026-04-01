#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};


Date createDate(int day, int month, int year) {
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    
    // Validate year
    if (year < 1900 || year > 2100) {
        cout << "Invalid year: " << year << " (must be between 1900 and 2100)" << endl;
        cout << "Setting to default year 2000" << endl;
        date.year = 2000;
    }
    
    // Validate month
    if (month < 1 || month > 12) {
        cout << "Invalid month: " << month << " (must be between 1 and 12)" << endl;
        cout << "Setting to default month 1" << endl;
        date.month = 1;
    }
    
    // Validate day based on month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    bool isLeapYear = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);
    if (isLeapYear) {
        daysInMonth[2] = 29;  // February has 29 days in leap year
    }
    
    int maxDays = daysInMonth[date.month];
    if (day < 1 || day > maxDays) {
        cout << "Invalid day: " << day << " (must be between 1 and " << maxDays << ")" << endl;
        cout << "Setting to default day 1" << endl;
        date.day = 1;
    }
    
    return date;
}

// Function to display Date
void displayDate(const Date& date) {
    cout << date.day << "/" << date.month << "/" << date.year << endl;
}

// Function to get day name
string getDayName(int day, int month, int year) {
    // Zeller's congruence for day of week
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    
    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    
    int h = (q + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    
    string dayNames[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return dayNames[h];
}

int main() {
    cout << "=== Function that Returns Struct Date with Validation ===" << endl << endl;
    

    cout << "Test Case 1: Valid date (15/3/2024)" << endl;
    Date date1 = createDate(15, 3, 2024);
    cout << "Returned Date: ";
    displayDate(date1);
    cout << "Day of week: " << getDayName(date1.day, date1.month, date1.year) << endl << endl;
    
    
    cout << "Test Case 2: Invalid day (31/2/2023)" << endl;
    Date date2 = createDate(31, 2, 2023);
    cout << "Returned Date: ";
    displayDate(date2);
    cout << endl;
  
    cout << "Test Case 3: Invalid month (15/13/2023)" << endl;
    Date date3 = createDate(15, 13, 2023);
    cout << "Returned Date: ";
    displayDate(date3);
    cout << endl;
    

    cout << "Test Case 4: Invalid year (15/3/1800)" << endl;
    Date date4 = createDate(15, 3, 1800);
    cout << "Returned Date: ";
    displayDate(date4);
    cout << endl;
    
 
    cout << "Test Case 5: Leap year - valid date (29/2/2024)" << endl;
    Date date5 = createDate(29, 2, 2024);
    cout << "Returned Date: ";
    displayDate(date5);
    cout << "Day of week: " << getDayName(date5.day, date5.month, date5.year) << endl << endl;
    

    cout << "Test Case 6: Non-leap year - invalid (29/2/2023)" << endl;
    Date date6 = createDate(29, 2, 2023);
    cout << "Returned Date: ";
    displayDate(date6);
    cout << endl;
    

    cout << "Test Case 7: All invalid values (32/13/1800)" << endl;
    Date date7 = createDate(32, 13, 1800);
    cout << "Returned Date: ";
    displayDate(date7);
    cout << endl;
    
    return 0;
}
