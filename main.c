#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Struct to represent a contact
struct Contact {
    char name[50];
    char email[50];
    char phone[15];
    char category[20];
};

//Array to store contacts
struct Contact contacts[MAX_CONTACTS];

// Variable to Keep track of the number of contacts
int numContacts = 0;

//Function Prototyping
void addContact();
void modifyContact();
void deleteContact();
void searchContact();
void displayContact();

int main {

}
