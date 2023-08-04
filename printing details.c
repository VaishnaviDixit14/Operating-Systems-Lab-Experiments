#include <stdio.h>
#include <string.h>
//21BCE5126
struct Student {
    char name[50];
    int regNo;
    float marks[3];
};

int main() {
    struct Student s[5];

    // Inputting details of 5 students
    for (int i = 0; i < 5; i++) {
        printf("\nEnter details of student %d:\n", i+1);
        printf("Name: ");
        fgets(s[i].name, 50, stdin); // Using fgets to input string with spaces
        printf("Registration Number: ");
        scanf("%d", &s[i].regNo);
        printf("Marks in Subject 1: ");
        scanf("%f", &s[i].marks[0]);
        printf("Marks in Subject 2: ");
        scanf("%f", &s[i].marks[1]);
        printf("Marks in Subject 3: ");
        scanf("%f", &s[i].marks[2]);
        getchar(); // To consume the newline character left by scanf
    }

    // Displaying details of 5 students
    printf("\nDetails of all 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Name: %s", s[i].name);
        printf("Registration Number: %d\n", s[i].regNo);
        printf("Marks in Subject 1: %.2f\n", s[i].marks[0]);
        printf("Marks in Subject 2: %.2f\n", s[i].marks[1]);
        printf("Marks in Subject 3: %.2f\n", s[i].marks[2]);
    }

    return 0;
}

