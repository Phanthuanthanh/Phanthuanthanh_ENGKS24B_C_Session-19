#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;

void sapXepSinhVien(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void inDanhSachSinhVien(SinhVien arr[], int n) {
    printf("%-5s %-20s %-5s %-15s\n", "ID", "Ten", "Tuoi", "So Dien Thoai");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-5d %-15s\n", arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
    }
}

int main() {
    SinhVien danhSach[5] = {
        {1, "Phan Thuan Thanh", 18, "088881111"},
        {2, "Le Trung Phong", 18, "088882222"},
        {3, "Cao Hoang An", 18, "088883333"},
        {4, "Vo Trung Hieu", 18, "088884444"},
        {5, "Bao Nhi", 18, "08885555"}
    };

    printf("Danh sach sinh vien truoc khi sap xep:\n");
    inDanhSachSinhVien(danhSach, 5);

    sapXepSinhVien(danhSach, 5);

    printf("\nDanh sach sinh vien sau khi sap xep:\n");
    inDanhSachSinhVien(danhSach, 5);

    return 0;
}

