/*
Written by : Ryan Vales
Written on : 7/21/21
Assignment : RyanValesFinalExam.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Contact { // Class for contacts.
    private: // Private access for data members.
        string contactName = "";
        string contactEmail = "";
        string contactPhoneNumber = "";
    public: // Public access for member functions that work with data members.
        void setContactName(string);
        string getContactName();

        void setContactEmail(string);
        string getContactEmail();

        void setContactPhoneNumber(string);
        string getContactPhoneNumber();
};

// Function definitions for member functions.
void Contact::setContactName(string contactNameParam) { // Setter function for contactName data member of Contact class object.
    contactName = contactNameParam;
}
string Contact::getContactName() { // Getter function for contactName data member of Contact class object.
    return contactName;
}

void Contact::setContactEmail(string contactEmailParam) { // Setter function for contactEmail data member of Contact class object.
    contactEmail = contactEmailParam;
}
string Contact::getContactEmail() { // Getter function for contactEmail data member of Contact class object.
    return contactEmail;
}

void Contact::setContactPhoneNumber(string contactPhoneNumberParam) { // Setter function for contactPhoneNumber data member of Contact class object.
    contactPhoneNumber = contactPhoneNumberParam;
}
string Contact::getContactPhoneNumber() { // Getter function for contactPhoneNumber data member of Contact class object.
    return contactPhoneNumber;
}

vector<Contact> contactsVector; // Vector to hold all contacts.

bool terminateProgram = false; // This global boolean will determine whether the program should terminate.

void displayAllContacts() { // Function displayAllContacts() will show the user all Contact objects in the contactsVector.
    if (contactsVector.empty()) { // If there are no items in the container, throw a runtime_error exception.
        throw runtime_error("There are no contacts in the list."); 
    } else { // Otherwise perform the intended function operations.
        for (int i = 0; i < contactsVector.size(); i++) {
            cout << i + 1 << ". " << contactsVector[i].getContactName() << "\n\n";
        }
    }
}

void viewContact() { // Function viewContact() will show the user a desired Contact in the contactsVector.
    if (contactsVector.empty()) { // If there are no items in the container, throw a runtime_error exception.
        throw runtime_error("There are no contacts in the list.");
    } else {
        cout << "Number: ";
        int contactToView;
        cin >> contactToView;
        contactToView -= 1; // This is to make the user input align with the index of the contact they wish to view.

        cout << "Name: " << contactsVector[contactToView].getContactName() << endl;
        cout << "Email: " << contactsVector[contactToView].getContactEmail() << endl;
        cout << "Phone: " << contactsVector[contactToView].getContactPhoneNumber() << endl;

        cout << "\n\n";
    }
}

void addNewContact() { // Function addNewContact() will allow the user to add a new Contact object to the contactsVector.
    Contact newContact;

    string newContactName;
    string newContactEmail;
    string newContactPhoneNumber;

    cout << "Name: ";
    cin.ignore();
    getline(cin, newContactName);

    newContact.setContactName(newContactName); // Set contactName for newContact class object.

    cout << "Email: ";
    getline(cin, newContactEmail);

    newContact.setContactEmail(newContactEmail); // Set contactEmail for newContact class object.

    cout << "Phone: ";
    getline(cin, newContactPhoneNumber);
    if (newContactPhoneNumber.size() != 12) { // If the user enters a phone number of the incorrect length, throw a runtime_error exception.
        throw runtime_error("Invalid contact number.");
    } else { // Otherwise perform the intended function operations.
        newContact.setContactPhoneNumber(newContactPhoneNumber); // Set contactPhoneNumber for newContact class object.
        contactsVector.push_back(newContact); // Push the new Contact object to the back of the contactsVector.
        cout << newContact.getContactName() << " was added." << "\n\n"; // Inform the user the newContact was added.
    }
}

void deleteContact() { // Function deleteContact will allow the user to delete a contact from the contactsVector.
    if (contactsVector.empty()) { // If there are no items in the container, throw a runtime_error exception.
        throw runtime_error("There are no contacts in the list.");
    } else {
        cout << "Number: ";
        int contactToDelete;
        cin >> contactToDelete;

        if (contactToDelete < 1 || contactToDelete > contactsVector.size()) {
            cout << "Invalid contact number." << endl;
        }
        else {
            contactToDelete -= 1; // This is to make the user input align with the index of the contact they wish to delete.
            contactsVector.erase(contactsVector.begin() + contactToDelete);
            cout << "Contact was deleted." << "\n\n";
        }
    }
}

void exitProgram() { // Function exitProgram() will allow the user to exit the program.
    cout << "Bye!";
    terminateProgram = true;
}

enum class menuDisplay { // Enumeration menuDisplay will provide a list of constants to refer to in order to display the menu to the user.
    menuIntro,
    menuItemOne,
    menuItemTwo,
    menuItemThree,
    menuItemFour,
    menuItemFive
};

string displayMenuHelper(menuDisplay Display, string Item) { // Function displayMenuHelper() will act as a helper function to display menu to user utilizing an enumeration.
    switch (Display) {
        case menuDisplay::menuIntro:
            return Item;
        case menuDisplay::menuItemOne:
            return Item;
        case menuDisplay::menuItemTwo:
            return Item;
        case menuDisplay::menuItemThree:
            return Item;
        case menuDisplay::menuItemFour:
            return Item;
        case menuDisplay::menuItemFive:
            return Item;
    }
}

void displayMenuOptions() { // Function displayMenuOptions() will display the menu to the user.
    string commandMenu = "COMMAND MENU";

    string menuChoiceL = "l - Display all contacts";
    string menuChoiceV = "v - View a contact";
    string menuChoiceA = "a - Add a contact";
    string menuChoiceD = "d - Delete a contact";
    string menuChoiceX = "x - Exit program";

    cout << "Contact Manager" << "\n\n";
    
    menuDisplay display = menuDisplay::menuIntro;
    cout << displayMenuHelper(display, commandMenu) << endl;

    display = menuDisplay::menuItemOne;
    cout << displayMenuHelper(display, menuChoiceL) << endl;

    display = menuDisplay::menuItemTwo;
    cout << displayMenuHelper(display, menuChoiceV) << endl;

    display = menuDisplay::menuItemThree;
    cout << displayMenuHelper(display, menuChoiceA) << endl;

    display = menuDisplay::menuItemFour;
    cout << displayMenuHelper(display, menuChoiceD) << endl;

    display = menuDisplay::menuItemFive;
    cout << displayMenuHelper(display, menuChoiceX) << endl;

    cout << "\n\n";
}

void handleMenuSelections() { // Function handleMenuSelections() will handle user input in coorelation with the menu options
    enum class commandMenuOptions : char {
        optionOne = 'l',
        optionTwo = 'v',
        optionThree = 'a',
        optionFour = 'd',
        optionFive = 'x' 
    };

    cout << "Command: ";
    char userInput;
    cin >> userInput;

    commandMenuOptions menuSelection = static_cast<commandMenuOptions>(userInput); // Convert userInput to type commandMenuOptions for switch statement.

    switch (menuSelection) { // Switch statement to handle user input and call functions associated with the enumeration constants.
        case commandMenuOptions::optionOne:
            try {
                displayAllContacts(); // Try function displayAllContacts() to see if it throws an exception.
            }
            catch (runtime_error e) {
                cout << e.what() << "\n\n"; // Catch runtime_error exception and output error message to user.
            }
            break;
        
        case commandMenuOptions::optionTwo:
            try {
                viewContact(); // Try function viewContact() to see if it throws an exception.
            }
            catch (runtime_error e) {
                cout << e.what() << "\n\n"; // Catch runtime_error exception and output error message to user.
            }
            break;
        
        case commandMenuOptions::optionThree:
            try {
                addNewContact(); // Try function addNewContact() to see if it throws an exception.
            }
            catch(runtime_error e) {
                cout << e.what() << "\n\n"; // Catch runtime_error exception and output error message to user.
            }
            break;
        
        case commandMenuOptions::optionFour:
            try {
                deleteContact(); // Try function deleteContact() to see if it throws an exception.
            }
            catch (runtime_error e) {
                cout << e.what() << "\n\n"; // Catch runtime_error exception and output error message to user.
            }
            break;
        
        case commandMenuOptions::optionFive:
            exitProgram(); // Function exitProgram() wil set the value of boolean terminateProgram to true so as to exit the program.
            break;
    }
}

// Main function for function calls and main functionality of the program.
int main() { 
    while (!terminateProgram) { // Run main functionality of the program while user has not selected the option to exit.
        displayMenuOptions();
        handleMenuSelections();
    }
    
    return 0; // Exit program once the main functionality of the program ends.
}
