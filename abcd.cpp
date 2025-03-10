#include <iostream>
#include <vector>
#include <string>

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string email;

    Contact(std::string name, std::string phoneNumber, std::string email) :
        name(name), phoneNumber(phoneNumber), email(email) {}
};

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    void displayContacts() const {
        for (const auto& contact : contacts) {
            std::cout << "Name: " << contact.name << std::endl;
            std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
            std::cout << "Email: " << contact.email << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
    }

    void searchContact(const std::string& name) const {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                std::cout << "Name: " << contact.name << std::endl;
                std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
                std::cout << "Email: " << contact.email << std::endl;
                return;
            }
        }
        std::cout << "Contact not found." << std::endl;
    }
};

int main() {
    ContactManager manager;

    manager.addContact(Contact("John Doe", "123-456-7890", "john.doe@example.com"));
    manager.addContact(Contact("Jane Smith", "987-654-3210", "jane.smith@example.com"));

    std::cout << "All Contacts:" << std::endl;
    manager.displayContacts();

    std::cout << "Searching for John Doe:" << std::endl;
    manager.searchContact("John Doe");

    return 0;
}
