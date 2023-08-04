#include <stdio.h>
#include <string.h>
//21BCE5126
struct Student {
    char name[50];
    char regNo[10];
    int marks[3];
};

int main() {
    struct Student s;

    strcpy(s.name, "Tanmay Wani");
    strcpy(s.regNo,"21BCE5126");
    s.marks[0] = 100;
    s.marks[1] = 100;
    s.marks[2] = 100;

    printf("Name: %s\n", s.name);
    printf("Registration Number: %s\n", s.regNo);
    printf("Marks in Subject 1: %d\n", s.marks[0]);
    printf("Marks in Subject 2: %d\n", s.marks[1]);
    printf("Marks in Subject 3: %d\n", s.marks[2]);

    return 0;
}

