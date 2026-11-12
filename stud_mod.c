#include "student.h"

static int valid_percentage(float percentage)
{
    return percentage >= 0.0f && percentage <= 100.0f;
}

static void update_student(struct student *temp)
{
    char new_name[50];
    float new_percentage;

    printf("\nCurrent details:\n");
    printf("Roll number: %d\n", temp->rollno);
    printf("Name: %s\n", temp->name);
    printf("Percentage: %.2f\n", temp->percentage);

    printf("Enter updated name: ");
    if (scanf(" %49[^\n]", new_name) != 1)
    {
        printf("Invalid name. Record was not modified.\n");
        return;
    }

    while (1)
    {
        printf("Enter updated percentage (0 to 100): ");
        if (scanf("%f", &new_percentage) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (valid_percentage(new_percentage))
            break;

        printf("Percentage must be between 0 and 100.\n");
    }

    strcpy(temp->name, new_name);
    temp->percentage = new_percentage;

    printf("Record modified successfully. Roll number remains %d.\n",
           temp->rollno);
}

void stud_mod(struct student *head)
{
    struct student *temp;
    char choice;
    char name[50];
    int roll;
    int found = 0;
    float percentage;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\nR/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'r' || choice == 'R')
    {
        printf("Enter roll number: ");
        if (scanf("%d", &roll) != 1)
        {
            printf("Invalid roll number.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        temp = head;
        while (temp != NULL)
        {
            if (temp->rollno == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found)
        {
            printf("Student record not found.\n");
            return;
        }

        update_student(temp);
    }
    else if (choice == 'n' || choice == 'N')
    {
        printf("Enter student name: ");
        if (scanf(" %49[^\n]", name) != 1)
        {
            printf("Invalid name.\n");
            return;
        }

        temp = head;
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
            printf("No matching student found.\n");
            return;
        }

        printf("Enter roll number of the record to modify: ");
        if (scanf("%d", &roll) != 1)
        {
            printf("Invalid roll number.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        temp = head;
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

        update_student(temp);
    }
    else if (choice == 'p' || choice == 'P')
    {
        printf("Enter percentage to search: ");
        if (scanf("%f", &percentage) != 1)
        {
            printf("Invalid percentage.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        if (!valid_percentage(percentage))
        {
            printf("Percentage must be between 0 and 100.\n");
            return;
        }

        temp = head;
        printf("\nMatching records:\n");

        while (temp != NULL)
        {
            if (temp->percentage == percentage)
            {
                printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                found = 1;
            }
            temp = temp->next;
        }

        if (!found)
        {
            printf("No matching student found.\n");
            return;
        }

        printf("Enter roll number of the record to modify: ");
        if (scanf("%d", &roll) != 1)
        {
            printf("Invalid roll number.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        temp = head;
        while (temp != NULL)
        {
            if (temp->rollno == roll && temp->percentage == percentage)
                break;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("That roll number does not have the entered percentage.\n");
            return;
        }

        update_student(temp);
    }
    else
    {
        printf("Invalid choice.\n");
    }
}
