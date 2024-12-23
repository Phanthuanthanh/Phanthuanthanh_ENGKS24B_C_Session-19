#include <stdio.h>
#include <string.h>


typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

Student students[100];
int studentCount = 0;

void displayStudents() {
    if (studentCount == 0) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        printf("Danh sach sinh vien:\n");
        for (int i = 0; i < studentCount; i++) {
            printf("ID: %d, Ten: %s, Diem: %.2f\n", students[i].id, students[i].name, students[i].grade);
        }
    }
}

void addStudent() {
    if (studentCount >= 100) {
        printf("Danh sach da day. Khong the them sinh vien moi.\n");
        return;
    }
    Student s;
    printf("Nhap ID: ");
    scanf("%d", &s.id);
    getchar();
    printf("Nhap ten: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Nhap diem: ");
    scanf("%f", &s.grade);
    students[studentCount++] = s;
    printf("Them sinh vien thanh cong!\n");
}

void editStudent() {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Nhap ten moi: ");
            getchar();
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            printf("Nhap diem moi: ");
            scanf("%f", &students[i].grade);
            printf("Sua thong tin sinh vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d.\n", id);
}

void deleteStudent() {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Xoa sinh vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d.\n", id);
}

void searchStudent() {
    char name[50];
    printf("Nhap ten sinh vien can tim: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strstr(students[i].name, name) != NULL) {
            printf("ID: %d, Ten: %s, Diem: %.2f\n", students[i].id, students[i].name, students[i].grade);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ten %s.\n", name);
    }
}

void sortStudents() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].grade < students[j].grade) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Sap xep danh sach thanh cong!\n");
}

void menu() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStudents();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}

