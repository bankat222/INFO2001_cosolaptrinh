#include <stdio.h>
int main() {
    float score;
    float totalScore = 0;
    float average;

    int Students;

    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &Students);

    while (getchar() != '\n');

    for (int i = 0; i < Students; i++) {
        printf("Nhap diem cua sinh vien thu %d:\n", i + 1);
        printf("Diem so: ");
        scanf("%f", &score);

        totalScore += score;

        while (getchar() != '\n');
    }
    average = totalScore / Students;

    printf("\nDiem trung binh cua lop la:%.2f\n", average);

    return 0;
}
