#include <iostream>
#include <string>
using namespace std;

// Enum for user roles
enum UserRole {
    ADMIN = 0,
    MANAGER = 1,
    USER = 2,
    GUEST = 3
};

// Struct using bit fields for permissions
struct UserPermissions {
    unsigned int canRead : 1;      // 1 bit for read permission
    unsigned int canWrite : 1;     // 1 bit for write permission
    unsigned int canDelete : 1;    // 1 bit for delete permission
    unsigned int canModify : 1;    // 1 bit for modify permission
    unsigned int canExecute : 1;   // 1 bit for execute permission
    unsigned int isActive : 1;     // 1 bit for active status
    unsigned int : 2;              // 2 unused bits
};

struct User {
    int id;
    string username;
    UserRole role;
    UserPermissions permissions;
};

// Function to display user role
void displayRole(UserRole role) {
    switch(role) {
        case ADMIN:
            cout << "ADMIN";
            break;
        case MANAGER:
            cout << "MANAGER";
            break;
        case USER:
            cout << "USER";
            break;
        case GUEST:
            cout << "GUEST";
            break;
    }
}

// Function to display permissions
void displayPermissions(const User& user) {
    cout << "Permissions:" << endl;
    cout << "  Read: " << (user.permissions.canRead ? "Yes" : "No") << endl;
    cout << "  Write: " << (user.permissions.canWrite ? "Yes" : "No") << endl;
    cout << "  Delete: " << (user.permissions.canDelete ? "Yes" : "No") << endl;
    cout << "  Modify: " << (user.permissions.canModify ? "Yes" : "No") << endl;
    cout << "  Execute: " << (user.permissions.canExecute ? "Yes" : "No") << endl;
    cout << "  Active: " << (user.permissions.isActive ? "Yes" : "No") << endl;
}

// Function to set permissions based on role
void setDefaultPermissions(User& user) {
    switch(user.role) {
        case ADMIN:
            // Admin has all permissions
            user.permissions.canRead = 1;
            user.permissions.canWrite = 1;
            user.permissions.canDelete = 1;
            user.permissions.canModify = 1;
            user.permissions.canExecute = 1;
            user.permissions.isActive = 1;
            break;
            
        case MANAGER:
            // Manager can read, write, modify
            user.permissions.canRead = 1;
            user.permissions.canWrite = 1;
            user.permissions.canDelete = 0;
            user.permissions.canModify = 1;
            user.permissions.canExecute = 0;
            user.permissions.isActive = 1;
            break;
            
        case USER:
            // User can read and write
            user.permissions.canRead = 1;
            user.permissions.canWrite = 1;
            user.permissions.canDelete = 0;
            user.permissions.canModify = 0;
            user.permissions.canExecute = 0;
            user.permissions.isActive = 1;
            break;
            
        case GUEST:
            // Guest can only read
            user.permissions.canRead = 1;
            user.permissions.canWrite = 0;
            user.permissions.canDelete = 0;
            user.permissions.canModify = 0;
            user.permissions.canExecute = 0;
            user.permissions.isActive = 1;
            break;
    }
}

int main() {
    cout << "=== Enum with Bit Fields: User Roles and Permissions ===" << endl << endl;
    
    // Create users with different roles
    User adminUser, managerUser, normalUser, guestUser;
    
    // Initialize Admin
    adminUser.id = 1001;
    adminUser.username = "john_admin";
    adminUser.role = ADMIN;
    setDefaultPermissions(adminUser);
    
    // Initialize Manager
    managerUser.id = 1002;
    managerUser.username = "sarah_manager";
    managerUser.role = MANAGER;
    setDefaultPermissions(managerUser);
    
    // Initialize User
    normalUser.id = 1003;
    normalUser.username = "mike_user";
    normalUser.role = USER;
    setDefaultPermissions(normalUser);
    
    // Initialize Guest
    guestUser.id = 1004;
    guestUser.username = "guest_visitor";
    guestUser.role = GUEST;
    setDefaultPermissions(guestUser);
    
    // Display all users
    cout << "User 1:" << endl;
    cout << "ID: " << adminUser.id << endl;
    cout << "Username: " << adminUser.username << endl;
    cout << "Role: "; displayRole(adminUser.role); cout << endl;
    displayPermissions(adminUser);
    cout << "\nBit field size: " << sizeof(UserPermissions) << " byte(s)" << endl;
    cout << string(70, '-') << endl << endl;
    
    cout << "User 2:" << endl;
    cout << "ID: " << managerUser.id << endl;
    cout << "Username: " << managerUser.username << endl;
    cout << "Role: "; displayRole(managerUser.role); cout << endl;
    displayPermissions(managerUser);
    cout << string(70, '-') << endl << endl;
    
    cout << "User 3:" << endl;
    cout << "ID: " << normalUser.id << endl;
    cout << "Username: " << normalUser.username << endl;
    cout << "Role: "; displayRole(normalUser.role); cout << endl;
    displayPermissions(normalUser);
    cout << string(70, '-') << endl << endl;
    
    cout << "User 4:" << endl;
    cout << "ID: " << guestUser.id << endl;
    cout << "Username: " << guestUser.username << endl;
    cout << "Role: "; displayRole(guestUser.role); cout << endl;
    displayPermissions(guestUser);
    cout << string(70, '-') << endl << endl;
    
    cout << "*** Bit Fields Benefits: ***" << endl;
    cout << "1. Memory efficient - each permission takes only 1 bit" << endl;
    cout << "2. UserPermissions struct size: " << sizeof(UserPermissions) << " byte(s)" << endl;
    cout << "3. Instead of 6 bool (24 bytes), we use just 1 byte" << endl;
    cout << "4. Useful for flags and permission systems" << endl;
    
    return 0;
}
