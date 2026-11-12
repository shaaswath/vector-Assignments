#include "student.h"

void stud_delAll(struct student **head)
{
    struct student *temp;

    if (*head == NULL)
    {
        printf("No student records to delete.\n");
        return;
    }

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *head = NULL;
    printf("All student records deleted from memory.\n");
}
