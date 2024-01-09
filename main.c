#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Struct to represent a contact
struct Contact {
    int id;
    char name[50];
    char email[50];
    char phone[15];
    int category;

};


// Variable to Keep track of the number of contacts
int numContacts = 0;

//Function Prototyping
void addContact(struct Contact contacts[], int *numContacts, int *nextId);
void modifyContact();
void deleteContact();
void searchContact();
void displayContact();

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int nextId = 1; // ID for the next contact to be added
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Modify Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts, &nextId);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                modifyContact(contacts, numContacts);
                break;
            case 5:
                deleteContact(contacts, &numContacts);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
