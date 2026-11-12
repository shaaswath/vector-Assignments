#include "student.h"

void stud_sort(struct student **head)
{
    struct student *i, *j;
    char choice;
    int temp_roll;
    char temp_name[50];
    float temp_percentage;
    int swap;

    if (*head == NULL || (*head)->next == NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }

    printf("\nN/n : Sort by name (A to Z)\n");
    printf("P/p : Sort by percentage (highest first)\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice != 'n' && choice != 'N' &&
        choice != 'p' && choice != 'P')
    {
        printf("Invalid choice.\n");
        return;
    }

    for (i = *head; i->next != NULL; i = i->next)
    {
        for (j = *head; j->next != NULL; j = j->next)
        {
            swap = 0;

            if (choice == 'n' || choice == 'N')
            {
                if (strcmp(j->name, j->next->name) > 0)
                    swap = 1;
            }
            else
            {
                if (j->percentage < j->next->percentage)
                    swap = 1;
            }

            if (swap)
            {
                temp_roll = j->rollno;
                strcpy(temp_name, j->name);
                temp_percentage = j->percentage;

                j->rollno = j->next->rollno;
                strcpy(j->name, j->next->name);
                j->percentage = j->next->percentage;

                j->next->rollno = temp_roll;
                strcpy(j->next->name, temp_name);
                j->next->percentage = temp_percentage;
            }
        }
    }

    printf("Records sorted successfully.\n");
}
