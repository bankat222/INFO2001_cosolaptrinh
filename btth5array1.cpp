#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int arrBubble[n], arrSelection[n];

    printf("Nhap cac phan tu: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arrBubble[i]);
        arrSelection[i] = arrBubble[i];
    }
    clock_t start_bubble = clock();
    bubbleSort(arrBubble, n);
    clock_t end_bubble = clock();

    printf("Mang sau Bubble Sort: ");
    printArray(arrBubble, n);
    printf("Thoi gian Bubble Sort: %.6f seconds\n", (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC);

    clock_t start_selection = clock();
    selectionSort(arrSelection, n);
    clock_t end_selection = clock();

    printf("\nMang sau Selection Sort: ");
    printArray(arrSelection, n);
    printf("Thoi gian Selection Sort: %.6f seconds\n", (double)(end_selection - start_selection) / CLOCKS_PER_SEC);

    return 0;
}
