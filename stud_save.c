#include "student.h"

struct student_file_record
{
    int rollno;
    char name[50];
    float percentage;
};

void stud_save(struct student *head)
{
    FILE *fp;
    struct student *temp;
    struct student_file_record record;

    fp = fopen("student.dat", "wb");
    if (fp == NULL)
    {
        perror("Unable to open student.dat for writing");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        record.rollno = temp->rollno;
        strcpy(record.name, temp->name);
        record.percentage = temp->percentage;

        if (fwrite(&record, sizeof(record), 1, fp) != 1)
        {
            printf("Error while writing student records.\n");
            fclose(fp);
            return;
        }

        temp = temp->next;
    }

    fclose(fp);
    printf("Student records saved successfully in student.dat.\n");
}

void stud_load(struct student **head)
{
    FILE *fp;
    struct student_file_record record;
    struct student *newnode;
    struct student *tail = NULL;

    fp = fopen("student.dat", "rb");
    if (fp == NULL)
    {
        return;
    }

    while (fread(&record, sizeof(record), 1, fp) == 1)
    {
        if (record.rollno <= 0 ||
            record.name[0] == '\0' ||
            record.percentage < 0.0f ||
            record.percentage > 100.0f)
            continue;

        newnode = malloc(sizeof(struct student));
        if (newnode == NULL)
        {
            printf("Memory allocation failed while loading records.\n");
            fclose(fp);
            return;
        }

        newnode->rollno = record.rollno;
        strcpy(newnode->name, record.name);
        newnode->percentage = record.percentage;
        newnode->next = NULL;

        if (*head == NULL)
        {
            *head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    fclose(fp);
    printf("Saved student records loaded successfully.\n");
}
