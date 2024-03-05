#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student 
{
    char name[50];
    int rollNumber;
    float marks;
};

void addStudent(struct Student *students, int *numStudents) 
{
    printf("Enter student name: ");
    scanf(" %[^\n]s", students[*numStudents].name);

    printf("Enter roll number: ");
    scanf("%d", &students[*numStudents].rollNumber);

    printf("Enter marks: ");
    scanf("%f", &students[*numStudents].marks);

    (*numStudents)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student *students, int numStudents) 
{
    if (numStudents == 0) 
    {
        printf("No students in the database.\n");
        return;
    }

    printf("\n%-20s%-15s%-10s\n", "Name", "Roll Number", "Marks");
    for (int i = 0; i < numStudents; i++) 
    {
        printf("%-20s%-15d%-10.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
    }
}

void deleteSelectedStudent(struct Student *students, int *numStudents) 
{
    int rollToDelete;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollToDelete);

    int found = 0;
    for (int i = 0; i < *numStudents; i++) 
    {
        if (students[i].rollNumber == rollToDelete) 
        {
            for (int j = i; j < *numStudents - 1; j++) 
            {
                students[j] = students[j + 1];
            }
            (*numStudents)--;
            found = 1;
            printf("Student with roll number %d deleted successfully.\n", rollToDelete);
            break;
        }
    }

    if (!found) 
    {
        printf("Student with roll number %d not found.\n", rollToDelete);
    }
}

void deleteAllStudents(int *numStudents) 
{
    *numStudents = 0;
    printf("All students deleted successfully.\n");
}

void editStudentDetails(struct Student *students, int numStudents) 
{
    int rollToEdit;
    printf("Enter the roll number of the student to edit: ");
    scanf("%d", &rollToEdit);

    int found = 0;
    for (int i = 0; i < numStudents; i++) 
    {
        if (students[i].rollNumber == rollToEdit) 
        {
            printf("Edit Options:\n");
            printf("1. Edit Name\n");
            printf("2. Edit Roll Number\n");
            printf("3. Edit Marks\n");
            printf("Enter your choice: ");

            int editChoice;
            scanf("%d", &editChoice);

            switch (editChoice) {
                case 1:
                    printf("Enter the new name: ");
                    scanf(" %[^\n]s", students[i].name);
                    printf("Name updated successfully.\n");
                    break;
                case 2:
                    printf("Enter the new roll number: ");
                    scanf("%d", &students[i].rollNumber);
                    printf("Roll number updated successfully.\n");
                    break;
                case 3:
                    printf("Enter the new marks: ");
                    scanf("%f", &students[i].marks);
                    printf("Marks updated successfully.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Student with roll number %d not found.\n", rollToEdit);
    }
}

int main() 
{
    struct Student students[100];
    int numStudents = 0;
    int choice;

    do 
    {
        printf("\nStudent Database Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Edit Student Details\n");
        printf("5. Delete All Students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                printf("\nDelete Options:\n");
                printf("1. Delete Selected Student\n");
                printf("2. Delete All Students\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1) 
                {
                    deleteSelectedStudent(students, &numStudents);
                } 
                else if (choice == 2) 
                {
                    deleteAllStudents(&numStudents);
                } 
                else 
                {
                    printf("Invalid choice.\n");
                }
                break;
            case 4:
                editStudentDetails(students, numStudents);
                break;
            case 5:
                deleteAllStudents(&numStudents);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
