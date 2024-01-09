#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char email[50];
    char phone[15];
    char category[20];
};