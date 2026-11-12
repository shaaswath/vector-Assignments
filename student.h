
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

void stud_add(struct student **head);
void stud_del(struct student **head);
void stud_show(struct student *head);
void stud_mod(struct student *head);
void stud_save(struct student *head);
void stud_load(struct student **head);
void stud_sort(struct student **head);
void stud_delAll(struct student **head);
void stud_rev(struct student **head);

