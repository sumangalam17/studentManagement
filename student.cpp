#include<stdio.h>
#include <string.h>

struct Student{
    int rollNo;
    char name[50];
    float marks;
};
struct Student student[1000];
int studentCount = 0;

void addStudent() {
    
    struct Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.rollNo);
    printf("Enter name: ");
    scanf(" %[^\n]", s.name);  // to read full name including spaces
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    student[studentCount] = s;
    studentCount++;
    printf("Student added successfully!\n");
}
void displayStudents() {
    if(studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for(int i = 0; i < studentCount; i++) {
        printf("Roll No: %d\n", student[i].rollNo);
        printf("Name: %s\n", student[i].name);
        printf("Marks: %.2f\n", student[i].marks);
        printf("-----------------------\n");
    }
}
void deleteStudent() {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    for(int i = 0; i < studentCount; i++) {
        if(student[i].rollNo == roll) {
            for(int j = i; j < studentCount - 1; j++) {
                student[j] = student[j+1];
            }
            studentCount--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}
void updateStudent() {
    int roll;
    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    for(int i = 0; i < studentCount; i++) {
        if(student[i].rollNo == roll) {
            printf("Enter new name: ");
            scanf(" %[^\n]", student[i].name);
            printf("Enter new marks: ");
            scanf("%f", &student[i].marks);
            printf("Student record updated!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int main(){
    int choice;
    
    while(true) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("%d \n", choice);
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: displayStudents(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}