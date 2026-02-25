//add code below
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;
#include <iostream>

// Structure to store contact details
struct Contact {
    string name;
    string phone;
};

// Function to add a contact
void addContact(vector<Contact>& contacts) {
    Contact newContact;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, newContact.name);

    cout << "Enter Phone: ";
    getline(cin, newContact.phone);

    contacts.push_back(newContact);
    cout << "Contact added successfully!\n";
}

// Function to display all contacts
void displayContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts found.\n";
        return;
    }

    cout << "\n--- Contact List ---\n";
    for (size_t i = 0; i < contacts.size(); i++) {
        cout << "\nContact " << i + 1 << ":\n";
        cout << "Name: " << contacts[i].name << endl;
        cout << "Phone: " << contacts[i].phone << endl;
    }
}

// Function to search contact by name
void searchContact(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');// why use limit??

    string searchName;
    cout << "Enter name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name == searchName) {
            cout << "\nContact Found:\n";
            cout << "Name: " << contact.name << endl;
            cout << "Phone: " << contact.phone << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found.\n";
    }
}

// Function to sort contacts
void sortContacts(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to sort.\n";
        return;
    }

    sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.name < b.name;
    });

    cout << "Contacts sorted successfully!\n";
}

// Function to delete contact
void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to delete.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string deleteName;
    cout << "Enter name to delete: ";
    getline(cin, deleteName);

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == deleteName) {
            contacts.erase(it);
            cout << "Contact deleted successfully!\n";
            return;
        }
    }

    cout << "Contact not found.\n";
}

int main() {
    vector<Contact> contacts;
    int choice = 0;

    do {
        cout << "\n===== Contact List Menu =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Sort Contacts\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                sortContacts(contacts);//sort contact from a-z
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }

    } while (choice != 6);

    return 0;
}
