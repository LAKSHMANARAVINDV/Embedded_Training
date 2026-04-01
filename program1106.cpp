#include <iostream>
#include <string>
using namespace std;

// Structure using bit fields for boolean flags
struct UserAccount {
    unsigned int isAdmin : 1;          // 1 bit - Admin privilege
    unsigned int isActive : 1;         // 1 bit - Account active status
    unsigned int isVerified : 1;       // 1 bit - Email verified
    unsigned int isLocked : 1;         // 1 bit - Account locked
    unsigned int twoFactorEnabled : 1; // 1 bit - Two-factor authentication
    unsigned int emailNotifications : 1; // 1 bit - Email notifications preference
    unsigned int smsNotifications : 1;   // 1 bit - SMS notifications preference
    unsigned int : 1;                  // 1 unused bit (padding to byte boundary)
};

struct AccountInfo {
    int accountId;
    string username;
    string email;
    UserAccount flags;
};

// Function to toggle a flag
void toggleFlag(unsigned int& flag) {
    flag = !flag;
}

// Function to display account status
void displayAccountStatus(const AccountInfo& account) {
    cout << "Account ID: " << account.accountId << endl;
    cout << "Username: " << account.username << endl;
    cout << "Email: " << account.email << endl;
    cout << "\nAccount Flags:" << endl;
    cout << "  Is Admin: " << (account.flags.isAdmin ? "YES" : "NO") << endl;
    cout << "  Is Active: " << (account.flags.isActive ? "YES" : "NO") << endl;
    cout << "  Is Verified: " << (account.flags.isVerified ? "YES" : "NO") << endl;
    cout << "  Is Locked: " << (account.flags.isLocked ? "YES" : "NO") << endl;
    cout << "  2FA Enabled: " << (account.flags.twoFactorEnabled ? "YES" : "NO") << endl;
    cout << "  Email Notifications: " << (account.flags.emailNotifications ? "ON" : "OFF") << endl;
    cout << "  SMS Notifications: " << (account.flags.smsNotifications ? "ON" : "OFF") << endl;
}

// Function to initialize a standard user account
void initializeStandardUser(AccountInfo& account, int id, string username, string email) {
    account.accountId = id;
    account.username = username;
    account.email = email;
    
    account.flags.isAdmin = 0;
    account.flags.isActive = 1;
    account.flags.isVerified = 0;
    account.flags.isLocked = 0;
    account.flags.twoFactorEnabled = 0;
    account.flags.emailNotifications = 1;
    account.flags.smsNotifications = 0;
}

// Function to initialize an admin account
void initializeAdminAccount(AccountInfo& account, int id, string username, string email) {
    account.accountId = id;
    account.username = username;
    account.email = email;
    
    account.flags.isAdmin = 1;
    account.flags.isActive = 1;
    account.flags.isVerified = 1;
    account.flags.isLocked = 0;
    account.flags.twoFactorEnabled = 1;
    account.flags.emailNotifications = 1;
    account.flags.smsNotifications = 1;
}

int main() {
    cout << "=== Structure with Boolean Flags using Bit Fields ===" << endl << endl;
    
    AccountInfo account1, account2, account3;
    
    // Initialize Account 1 - Standard User
    initializeStandardUser(account1, 2001, "alice_smith", "alice@example.com");
    
    cout << "Account 1 (Standard User) - Initial State:" << endl;
    cout << string(50, '-') << endl;
    displayAccountStatus(account1);
    
    cout << "\n\nModifying Account 1 flags..." << endl;
    account1.flags.isVerified = 1;
    account1.flags.twoFactorEnabled = 1;
    account1.flags.smsNotifications = 1;
    
    cout << "\nAccount 1 - After Modifications:" << endl;
    cout << string(50, '-') << endl;
    displayAccountStatus(account1);
    
    cout << "\n\n" << string(70, '=') << endl;
    
    // Initialize Account 2 - Admin User
    initializeAdminAccount(account2, 2002, "admin_bob", "admin@example.com");
    
    cout << "\nAccount 2 (Admin User) - Initial State:" << endl;
    cout << string(50, '-') << endl;
    displayAccountStatus(account2);
    
    cout << "\n\nLocking admin account..." << endl;
    account2.flags.isLocked = 1;
    account2.flags.isActive = 0;
    
    cout << "\nAccount 2 - After Locking:" << endl;
    cout << string(50, '-') << endl;
    displayAccountStatus(account2);
    
    cout << "\n\n" << string(70, '=') << endl;
    
    // Initialize Account 3 - Suspended User
    initializeStandardUser(account3, 2003, "charlie_john", "charlie@example.com");
    account3.flags.isActive = 0;
    account3.flags.isLocked = 1;
    
    cout << "\nAccount 3 (Suspended User):" << endl;
    cout << string(50, '-') << endl;
    displayAccountStatus(account3);
    
    cout << "\n\n" << string(70, '=') << endl;
    
    // Memory efficiency comparison
    cout << "\nMemory Usage Comparison:" << endl;
    cout << "Size of UserAccount (with bit fields): " << sizeof(UserAccount) << " byte" << endl;
    cout << "Size of individual bool flags (7 bools): ~" << 7 << " bytes" << endl;
    cout << "Memory saved: " << (7 - sizeof(UserAccount)) << " bytes per account" << endl;
    
    // For 1000 accounts
    int numAccounts = 1000;
    cout << "\nFor " << numAccounts << " accounts:" << endl;
    cout << "Memory with bit fields: " << sizeof(UserAccount) * numAccounts << " bytes" << endl;
    cout << "Memory without bit fields: " << 7 * numAccounts << " bytes" << endl;
    cout << "Total savings: " << (7 - sizeof(UserAccount)) * numAccounts << " bytes" << endl;
    
    cout << "\n*** Bit Field Advantages: ***" << endl;
    cout << "1. Memory efficient - multiple boolean flags in single byte" << endl;
    cout << "2. Ideal for storing yes/no settings and states" << endl;
    cout << "3. Simplifies flag management in large systems" << endl;
    cout << "4. Fast access to individual boolean values" << endl;
    cout << "5. Common in kernel code, firmware, and embedded systems" << endl;
    
    return 0;
}
