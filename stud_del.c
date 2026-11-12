#include "student.h"

static void remove_by_roll(struct student **head, int roll)
{
    struct student *temp = *head;
    struct student *prev = NULL;

    while (temp != NULL && temp->rollno != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student record not found.\n");
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Record deleted successfully.\n");
}

void stud_del(struct student **head)
{
    struct student *temp;
    char choice;
    char name[50];
    int roll;
    int found = 0;

    if (*head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\nR/r : Delete by roll number\n");
    printf("N/n : Delete by name\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'r' || choice == 'R')
    {
        printf("Enter roll number to delete: ");
        if (scanf("%d", &roll) != 1)
        {
            printf("Invalid roll number.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        if (roll <= 0)
        {
            printf("Roll number must be positive.\n");
            return;
        }

        remove_by_roll(head, roll);
    }
    else if (choice == 'n' || choice == 'N')
    {
        printf("Enter student name: ");
        if (scanf(" %49[^\n]", name) != 1)
        {
            printf("Invalid name.\n");
            return;
        }

        temp = *head;
        printf("\nMatching records:\n");

        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                found = 1;
            }
            temp = temp->next;
        }

        if (!found)
        {
            printf("No student with that name was found.\n");
            return;
        }

        printf("Enter the roll number of the record to delete: ");
        if (scanf("%d", &roll) != 1)
        {
            printf("Invalid roll number.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        temp = *head;
        while (temp != NULL)
        {
            if (temp->rollno == roll && strcmp(temp->name, name) == 0)
                break;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("That roll number does not belong to the entered name.\n");
            return;
        }

        remove_by_roll(head, roll);
    }
    else
    {
        printf("Invalid choice.\n");
    }
}
