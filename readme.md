# Instructions 
AlgoWorks Corp requires a simple yet effective contact management system to streamline our communication and collaboration efforts. The system should enable users to manage and organize contacts efficiently, facilitating the easy retrieval of essential information when needed. The primary goal is to enhance communication within the organization.

### Key Features
Store essential information for each contact, including name, email, phone, and any additional relevant details.

### Categorization
Implement a feature that allows contacts to be categorized based on different criteria (e.g., clients, suppliers, internal team members).

### Search and Retrieval
Enable users to easily search for and retrieve specific contacts, based on various parameters (e.g., name, category).

### Modification and Deletion
Provide functionality to edit or delete existing contacts, ensuring that the database stays accurate and up-to-date.

### Modular Code Design
Ensure the system is designed with modular code principles to facilitate future enhancements and maintenance.

### Data Structures
Utilize appropriate data structures (e.g., structs) to organize and represent contact information.

### Functions
Implement functions for adding, modifying, deleting, and searching for contacts.

### Code Documentation
Include clear and concise documentation for the codebase to aid understanding and future development.

### Additional Requirements
The system should be developed using the C programming language.
Use only a console UI.
Include mock data retrieval functionalities, such as a mock array of contacts.

---
# Our Company
AlgoWorks Corp is a software development company that specializes in the development of custom software solutions for businesses. We are a team of highly skilled and experienced software engineers who are passionate about creating innovative solutions to solve real-world problems. Our mission is to help businesses achieve their goals by providing them with the tools they need to succeed.

## Our Team

| First Name | Role |
| --- | --- |
| David | CEO |
| Robin | CTO |
| Atifa | Software Engineer |
| Michel | Software Engineer |
| Pierre | Quality Assurance |


---

# Solution

## Data Structures

### Contact

- ID [integer] - (Mandatory)
- Name [string] - (Mandatory)
- Email [string] - (Mandatory)
- Phone [integer] - (Mandatory)
- Category [integer] - (Mandatory) - Select 1 for Internal Team Member, 2 for Client, 3 for Supplier

```c
typedef struct {
    int id;
    char name[50];
    char email[50];
    int phone;
    int category;
}
```

## Path
