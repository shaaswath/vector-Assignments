# vector-Assignments
This repository contains programs,tasks and completion of assignment tasks which was given by the  vector . 
# Student Record Management System

A menu-driven Student Record Management System written in C using a singly linked list and dynamic memory allocation.

## Files

- `student.h` – structure and function declarations
- `stud_main.c` – menu and program flow
- `stud_add.c` – add student records
- `stud_del.c` – delete by roll number or name
- `stud_show.c` – display records
- `stud_mod.c` – modify records
- `stud_save.c` – save/load `student.dat`
- `stud_sort.c` – sort by name or percentage
- `stud_reverse.c` – reverse the linked list
- `stud_delete_all.c` – release all nodes

## Compile

Run this command in the project directory:

```bash
gcc -Wall -Wextra -std=c11 stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c stud_reverse.c stud_delete_all.c -o student
```

## Execute

./student

The program reads existing records from `student.dat` at startup if the file exists. Use the Save option or Save and Exit to write the current records to that file.

## Notes

- Roll numbers are automatically assigned as the smallest unused positive integer.
- Percentage must be between 0 and 100.
- `student.dat` stores student data, not process-specific linked-list pointers.
- Delete All removes nodes from memory; it does not delete or overwrite `student.dat`.
- Exit without saving discards changes made since the last save.
