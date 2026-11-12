#include "student.h"

void stud_rev(struct student **head)
{
    struct student *prev = NULL;
    struct student *current = *head;
    struct student *nextnode;

    if (*head == NULL || (*head)->next == NULL)
    {
        printf("List has fewer than two records; no reversal needed.\n");
        return;
    }

    while (current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    *head = prev;
    printf("Linked list reversed successfully.\n");
}
