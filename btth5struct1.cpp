#include <stdio.h>
#include <string.h>

const int MAX_STUDENTS = 1;

struct Student{
    char name[100];
    int age;
    double id;
    int grade;
};
void display(const Student& student) {
    printf("Ten: %s\nTuoi: %d\nId: %g\nDiem so: %d\n", student.name, student.age, student.id, student.grade);
};
void update(struct Student& student, const char name[100], int age, double id, int grade) {
    strncat(student.name, name, sizeof(student.name) - strlen(student.name) - 1);
    student.name[sizeof(student.name) - 1] = '\0';
    student.age = age;
    student.id = id;
    student.grade = grade;
};
int main() {
    Student information[MAX_STUDENTS];

    printf("Nhap thong tin sinh vien:\n");
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        char name[100];
        int age;
        double id;
        int grade;

        printf("Sinh vien %d:\n", i + 1);
        printf("Ten: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("Tuoi: ");
        scanf("%d", &age);
        printf("Id: ");
        scanf("%lf", &id);
        printf("Diem so: ");
        scanf("%d%*c", &grade);
        
        update(information[i], name, age, id, grade);
    };
    printf("\nThong tin sinh vien:\n");
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        display(information[i]);
    };
    printf("\nNhap so luong sinh vien can cap nhat: ", information);
    int studentNumber;
    scanf("%d", &studentNumber);

    if (studentNumber >= 1 && studentNumber <= MAX_STUDENTS) {
        char name[100];
        int age;
        double id;
        int grade;

        printf("Thong tin sinh vien:\n", studentNumber);
        printf("Ten: ");
        getchar();
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("Tuoi: ");
        scanf("%d", &age);
        printf("Id: ");
        scanf("%lf", &id);
        printf("Diem so: ");
        scanf("%d", &grade);

        update(information[studentNumber - 1], name, age, id, grade);

        printf("\nThong tin sinh vien da cap nhat:\n");
        display(information[studentNumber - 1]);
    } else {
        printf("Thong tin khong hop le.\n");
    }
 return 0;
}
