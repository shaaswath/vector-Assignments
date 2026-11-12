#include "student.h"

int main(void)
{
    struct student *head = NULL;
    char choice, exit_choice;

    stud_load(&head);

    while (1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all records\n");
        printf("r/R : Reverse the list\n");
        printf("Enter your choice: ");

        if (scanf(" %c", &choice) != 1)
            break;

        switch (choice)
        {
            case 'a':
            case 'A':
                stud_add(&head);
                break;

            case 'd':
            case 'D':
                stud_del(&head);
                break;

            case 's':
            case 'S':
                stud_show(head);
                break;

            case 'm':
            case 'M':
                stud_mod(head);
                break;

            case 'v':
            case 'V':
                stud_save(head);
                break;

            case 't':
            case 'T':
                stud_sort(&head);
                break;

            case 'l':
            case 'L':
                stud_delAll(&head);
                break;

            case 'r':
            case 'R':
                stud_rev(&head);
                break;

            case 'e':
            case 'E':
                printf("\nS/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter your choice: ");
                scanf(" %c", &exit_choice);

                if (exit_choice == 's' || exit_choice == 'S')
                {
                    stud_save(head);
                }
                else if (exit_choice != 'e' && exit_choice != 'E')
                {
                    printf("Invalid choice. Returning to main menu.\n");
                    break;
                }

                stud_delAll(&head);
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid menu choice. Try again.\n");
        }
    }

    stud_delAll(&head);
    return 0;
}
