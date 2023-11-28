#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float score;
};
void Name(struct Student students[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(students[j].name, students[j+1].name) > 0) {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}
void Score(struct Student students[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].score > students[j+1].score) {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap ten, id va diem cho sinh vien thu %d: ", i+1);
        scanf("%s %d %f", students[i].name, &students[i].id, &students[i].score);
    }
    Name(students, n);
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%.f\n", students[i].name, students[i].id, students[i].score);
    }
    Score(students, n);

    printf("\nDanh sach sinh vien sau khi sap xep theo diem:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%.f\n", students[i].name, students[i].id, students[i].score);
    }
    char targetStudent[50];
    printf("\nNhap ten sinh vien can tim: ");
    scanf("%s", targetStudent);
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, targetStudent) == 0) {
            printf("Sinh vien %s co id la %d va diem la %.f\n", students[i].name, students[i].id, students[i].score);
            return 0;
        }
    }
    printf("Khong tim thay sinh vien %s\n", targetStudent);
    return 0;
}