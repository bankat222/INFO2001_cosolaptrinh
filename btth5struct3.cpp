#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

int addEmployee(struct Employee employees[], int size, int n);
void displayEmployees(struct Employee employees[], int n);
int deleteEmployee(struct Employee employees[], int n, int id);
void sortEmployees(struct Employee employees[], int n);

int main() {
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap ten, id va luong cho nhan vien thu %d: ", i + 1);
        scanf("%s %d %f", employees[i].name, &employees[i].id, &employees[i].salary);
    }
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Hien thi danh sach nhan vien\n");
        printf("2. Them nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Sap xep nhan vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayEmployees(employees, n);
                break;
            case 2:
                n = addEmployee(employees, n, n);
                break;
            case 3: {
                int id;
                printf("Nhap ID nhan vien can xoa: ");
                scanf("%d", &id);
                n = deleteEmployee(employees, n, id);
                break;
            }
            case 4:
                sortEmployees(employees, n);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Chon chuc nang khong hop le.\n");
        }
    } while (choice != 0);

    return 0;
}
void displayEmployees(struct Employee employees[], int n) {
    printf("Danh sach nhan vien:\n");
    for (int i = 0; i < n; i++) {
        printf("Ten: %s, ID: %d, Luong: %.2f\n", employees[i].name, employees[i].id, employees[i].salary);
    }
}
int addEmployee(struct Employee employees[], int size, int n) {
        printf("Nhap ten, id va luong cho nhan vien moi: ");
        scanf("%s %d %f", employees[n].name, &employees[n].id, &employees[n].salary);
        return n + 1;
    }
int deleteEmployee(struct Employee employees[], int n, int id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].id == id) {
            found = 1;
            for (int j = i; j < n - 1; j++) {
                employees[j] = employees[j + 1];
            }
            printf("Da xoa nhan vien co ID: %d\n", id);
            return n - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay nhan vien co ID: %d\n", id);
    }
    return n;
}
void sortEmployees(struct Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employees[j].id > employees[j + 1].id) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep danh sach nhan vien theo ID.\n");
}