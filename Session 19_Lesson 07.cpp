#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void printStudents(Student students[], int currentLength) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
    printf("\n");
}

void deleteStudentById(int id, Student students[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;
            break;
        }
    }
    if (found) {
        printf("\nSinh vien voi ID %d da duoc xoa.\n", id);
    } else {
        printf("\nKhong tim thay sinh vien voi ID %d.\n", id);
    }
}

int main() {
    Student students[5] = {
        {1, "Phan Thuan Thanh", 18, "088881111"},
        {2, "Le Trung Phong", 18, "088882222"},
        {3, "Cao Hoang An", 18, "088883333"},
        {4, "Vo Trung Hieu", 18, "088884444"},
        {5, "Bao Nhi", 18, "08885555"}
    };

    int currentLength = 5;

    printStudents(students, currentLength);

    deleteStudentById(3, students, &currentLength);

    printStudents(students, currentLength);

    deleteStudentById(10, students, &currentLength);

    printStudents(students, currentLength);

    return 0;
}

