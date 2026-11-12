#include "student.h"

void stud_add(struct student **head)
{
    struct student *newnode, *temp;
    int roll = 1;
    int found;

    newnode = malloc(sizeof(struct student));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    while (1)
    {
        found = 0;
        temp = *head;

        while (temp != NULL)
        {
            if (temp->rollno == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (found == 0)
            break;

        roll++;
    }

    newnode->rollno = roll;

    printf("Enter student name: ");
    if (scanf(" %49[^\n]", newnode->name) != 1)
    {
        printf("Invalid name.\n");
        free(newnode);
        return;
    }

    while (1)
    {
        printf("Enter percentage (0 to 100): ");
        if (scanf("%f", &newnode->percentage) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (newnode->percentage >= 0.0f &&
            newnode->percentage <= 100.0f)
            break;

        printf("Percentage must be between 0 and 100.\n");
    }

    newnode->next = *head;
    *head = newnode;

    printf("Student added successfully. Assigned roll number: %d\n", roll);
}
