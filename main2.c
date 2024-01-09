/**
 * @file main2.c
 * @brief Contact Management System
 *
 * This program allows users to manage contacts by performing various operations such as adding a contact,
 * displaying all contacts, searching for a contact by name, modifying a contact, deleting a contact,
 * and adding multiple contacts in a formatted manner.
 *
 * The program uses a struct to represent a contact, with fields for ID, name, email, phone, and category.
 * The contacts are stored in an array, and the number of contacts and the ID for the next contact to be added
 * are tracked using variables.
 *
 * The main program loop presents a menu of options to the user and performs the corresponding operation
 * based on the user's choice. The program continues to loop until the user chooses to exit.
 *
 * The program includes functions for adding a contact, displaying all contacts, searching for a contact by name,
 * modifying a contact, deleting a contact, and adding multiple contacts in a formatted manner.
 *
 * @note The program has a maximum limit of 100 contacts.
 * @note The category values for contacts are as follows:
 *       - 1: Internal Team
 *       - 2: Client
 *       - 3: Supplier
 */
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

struct Contact contacts[MAX_CONTACTS];

// Variable to keep track of the number of contacts
int numContacts = 0;
int nextId = 1; // ID for the next contact to be added
int choice;

// Function Prototyping
void addContact(struct Contact contacts[], int *numContacts, int *nextId);
void modifyContact(struct Contact contacts[], int numContacts);
void deleteContact(struct Contact contacts[], int *numContacts);
void searchContact(struct Contact contacts[], int numContacts);
void displayContact(struct Contact contacts[], int numContacts);
void addMultipleContacts(struct Contact contacts[], int *numContacts, int *nextId);
void clearInputBuffer();

int main()
{
    // Main program loop
    do
    {
        printf("\n----------------------------------------------\n");
        printf("Contact Management System\n");
        printf("1. Add Contact \n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Modify Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Add Multiple Contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n----------------------------------------------\n");

        // Switch statement for user's choice
        switch (choice)
        {
        case 1:
            addContact(contacts, &numContacts, &nextId);
            break;
        case 2:
            displayContact(contacts, numContacts);
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
            addMultipleContacts(contacts, &numContacts, &nextId);
            break;
        case 7:
            printf("Exiting the program...\n");
            break;
        default:
            printf("❌ Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

// Function to add a contact
void addContact(struct Contact contacts[], int *numContacts, int *nextId)
{
    // Check if there is space to add a contact
    if (*numContacts < MAX_CONTACTS)
    {
        struct Contact newContact;
        newContact.id = (*nextId)++;
        printf("👤 Enter Name: ");
        scanf("%s", newContact.name);
        printf("📧 Enter Email: ");
        scanf("%s", newContact.email);
        printf("📱 Enter Phone: ");
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
            printf("❌ Invalid category. Setting category to 1 (Internal Team).\n");
            newContact.category = 1;
        }

        // Add the new contact to the array
        contacts[*numContacts] = newContact;
        (*numContacts)++;
        printf("✅ Contact added successfully!\n");
    }
    else
    {
        printf("❌ Contact limit reached. Cannot add more contacts.\n");
    }
}

// Function to display all contacts
void displayContact(struct Contact contacts[], int numContacts)
{
    // Check if there are contacts to display
    if (numContacts == 0)
    {
        printf("❌ No contacts to display.\n");
    }
    else
    {
        // Display contact information
        printf("ID\tName\tEmail\t\tPhone\t\tCategory\n");
        for (int i = 0; i < numContacts; i++)
        {
            struct Contact currentContact = contacts[i];
            printf("%d\t%s\t%s\t%s\t", currentContact.id, currentContact.name, currentContact.email, currentContact.phone);

            // Display category based on the category value
            switch (currentContact.category)
            {
            case 1:
                printf("Internal Team\n");
                break;
            case 2:
                printf("Client\n");
                break;
            case 3:
                printf("Supplier\n");
                break;
            }
        }
    }
}

// Function to search for a contact by name
void searchContact(struct Contact contacts[], int numContacts)
{
    // Check if there are contacts to search
    if (numContacts == 0)
    {
        printf("❌ No contacts to search.\n");
    }
    else
    {
        char name[50];
        printf("Enter name to search: ");
        scanf("%s", name);

        int found = 0;
        // Search for the contact
        for (int i = 0; i < numContacts; i++)
        {
            struct Contact currentContact = contacts[i];
            if (strcmp(currentContact.name, name) == 0)
            {
                // Display the found contact details
                printf("ID\tName\tEmail\t\tPhone\t\tCategory\n");
                printf("%d\t%s\t%s\t%s\t", currentContact.id, currentContact.name, currentContact.email, currentContact.phone);
                // Display category based on the category value
                switch (currentContact.category)
                {
                case 1:
                    printf("Internal Team\n");
                    break;
                case 2:
                    printf("Client\n");
                    break;
                case 3:
                    printf("Supplier\n");
                    break;
                }
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("❌ No matching contact found.\n");
        }
    }
}

// Function to modify a contact
void modifyContact(struct Contact contacts[], int numContacts)
{
    // Check if there are contacts to modify
    if (numContacts == 0)
    {
        printf("❌ No contacts to modify.\n");
    }
    else
    {
        int id;
        printf("🆔 Enter ID of contact to modify: ");
        scanf("%d", &id);

        int found = 0;
        // Search for the contact
        for (int i = 0; i < numContacts; i++)
        {
            struct Contact *currentContact = &contacts[i];
            if (currentContact->id == id)
            {
                // Modify contact details
                printf("👤 Enter Name: ");
                scanf("%s", currentContact->name);
                printf("📧 Enter Email: ");
                scanf("%s", currentContact->email);
                printf("📱 Enter Phone: ");
                scanf("%s", currentContact->phone);

                // Choose category
                printf("Choose Category:\n");
                printf("1. Internal Team\n");
                printf("2. Client\n");
                printf("3. Supplier\n");
                printf("Enter Category (1-3): ");
                scanf("%d", &currentContact->category);

                // Validate category input
                if (currentContact->category < 1 || currentContact->category > 3)
                {
                    printf("❌ Invalid category. Setting category to 1 (Internal Team).\n");
                    currentContact->category = 1;
                }

                printf("✅ Contact modified successfully!\n");
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("❌ No matching contact found.\n");
        }
    }
}

// Function to delete a contact
void deleteContact(struct Contact contacts[], int *numContacts)
{
    // Check if there are contacts to delete
    if (*numContacts == 0)
    {
        printf("❌ No contacts to delete.\n");
    }
    else
    {
        int id;
        printf("🆔 Enter ID of contact to delete: ");
        scanf("%d", &id);

        int found = 0;
        // Search for the contact
        for (int i = 0; i < *numContacts; i++)
        {
            struct Contact *currentContact = &contacts[i];
            if (currentContact->id == id)
            {
                // Delete the contact by shifting elements
                for (int j = i; j < *numContacts - 1; j++)
                {
                    contacts[j] = contacts[j + 1];
                }
                (*numContacts)--;
                printf("✅ Contact deleted successfully!\n");
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("❌ No matching contact found.\n");
        }
    }
}

// Function to add multiple contacts in a formatted manner
void addMultipleContacts(struct Contact contacts[], int *numContacts, int *nextId)
{
    char input[1024]; // Assuming maximum length of input string
    printf("Enter contacts in format \"Name\",\"Email\",Phone,Category;... : ");
    scanf(" %[^\n]", input); // Read the entire line, including spaces

    char *token = strtok(input, ";");
    while (token != NULL && *numContacts < MAX_CONTACTS)
    {
        char name[50], email[50], phone[15];
        int category;

        // Parse the input and add the contact
        if (sscanf(token, "\"%[^\"]\",\"%[^\"]\",%14[^,],%d", name, email, phone, &category) == 4)
        {
            struct Contact newContact;
            newContact.id = (*nextId)++;
            strncpy(newContact.name, name, sizeof(newContact.name));
            strncpy(newContact.email, email, sizeof(newContact.email));
            strncpy(newContact.phone, phone, sizeof(newContact.phone));
            newContact.category = (category >= 1 && category <= 3) ? category : 1;

            // Add the new contact to the array
            contacts[*numContacts] = newContact;
            (*numContacts)++;
            printf("✅ Contact '%s' added successfully!\n", name);
        }
        else
        {
            printf("❌ Invalid format for contact: %s\n", token);
        }

        token = strtok(NULL, ";");
    }

    // Check if the contact limit has been reached
    if (*numContacts >= MAX_CONTACTS)
    {
        printf("❌ Contact limit reached. Some contacts may not have been added.\n");
    }

    // Clear the input buffer
    clearInputBuffer();
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
