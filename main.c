#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Struct to represent a contact
struct Contact
{
    int id;
    char name[50];
    char email[50];
    char phone[15];
    int category;
};

// Array to store contacts
struct Contact contacts[MAX_CONTACTS];


// Variable to Keep track of the number of contacts
int numContacts = 0;

// Function Prototyping
void addContact();
void modifyContact();
void deleteContact();
void searchContact();
void displayContact();
const char* getCategoryName(int category);

int main()
{
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int nextId = 1; // ID for the next contact to be added
    int choice;

    do
    {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Modify Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
            modifyContact(contacts);
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
void addContact(struct Contact contacts[], int *numContacts, int *nextId)
{
    if (*numContacts < MAX_CONTACTS)
    {
        struct Contact newContact;
        newContact.id = (*nextId)++;
        printf("Enter Name: ");
        scanf("%s", newContact.name);
        printf("Enter Email: ");
        scanf("%s", newContact.email);
        printf("Enter Phone: ");
        scanf("%s", newContact.phone);

        // Choose category
        printf("Choose Category:\n");
        printf("1. Internal Team\n");
        printf("2. Client\n");
        printf("3. Supplier\n");
        printf("Enter Category (1-3): ");
        scanf("%d", &newContact.category);

        // Validate category input
        if (newContact.category < 1 || newContact.category > 3)
        {
            printf("Invalid category. Setting category to 1 (Internal Team).\n");
            newContact.category = 1;
        }

        contacts[*numContacts] = newContact;
        (*numContacts)++;
        printf("Contact added successfully!\n");
    }
    else
    {
        printf("Contact limit reached. Cannot add more contacts.\n");
    }
}

    void deleteContact()
{
    char searchName[50];
    int foundIndex = -1; 

    printf("Enter the name of the contact you want to delete: ");
    scanf("%s", searchName);

    for (int i = 0; i < numContacts; ++i) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        contacts[foundIndex] = contacts[numContacts - 1]; // Replace the deleted contact with the last contact
        numContacts--;
        printf("Contact '%s' has been deleted.\n", searchName);
    } else {
        printf("Contact '%s' not found.\n", searchName);
    }
}

void searchContact()
{
    char searchName[50];
    int foundIndex = -1;

    printf("\nEnter the name of the contact to search: ");
    scanf("%s", searchName);

    // Search for the contact
    for (int i = 0; i < numContacts; i++)
    {
        if (strcmp(contacts[i].name, searchName) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        // Display the found contact details
        printf("\nContact Details:\n");
        printf("Name: %s\n", contacts[foundIndex].name);
        printf("Email: %s\n", contacts[foundIndex].email);
        printf("Phone: %s\n", contacts[foundIndex].phone);
        printf("Category: %s\n", contacts[foundIndex].category);
    }
    else
    {
        printf("Contact not found.\n");
    }
}

    
void modifyContact(struct Contact contacts[]){
    int foundIndex;
    int id_detail;
    printf("Enter the ID you want modify:");
    scanf("%d", &foundIndex);
    foundIndex--;

    printf("What do you want to modify:");
    scanf("%d", &id_detail);

    switch(id_detail){
        case 1:
        printf("Name: %s, will be modified by :", contacts[foundIndex].name);
        scanf("%s", contacts[foundIndex].name);
        break;
        case 2:
        printf("Email: %s, will be modified by :", contacts[foundIndex].email);
        scanf("%s", contacts[foundIndex].email);
        break;
        case 3:
        printf("Phone: %s, will be modified by :", contacts[foundIndex].phone);
        scanf("%s", contacts[foundIndex].phone);
        break;
        case 4:
        printf("Category: %d, will be modified by :", contacts[foundIndex].category);
        scanf("%d", contacts[foundIndex].category);
        break;
        default:
        printf("unknow");
    }
    return 0;
}

const char* getCategoryName(int category) {
    switch (category) {
        case 1:
            return "Internal Team";
        case 2:
            return "Client";
        case 3:
            return "Supplier";
        default:
            return "Unknown";
    }
}

