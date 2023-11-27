#include <stdio.h>
int linearSearch(const int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
int binarySearch(const int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int birany[] = {1, 10, 11, 100};
    int linear[] = {2, 4, 5, 6, 8};

    int x;
    printf("Nhap gia tri: ");
    scanf("%d", &x);

    int linearIndex = linearSearch(linear, sizeof(linear) / sizeof(linear[0]), x);
    if (linearIndex != -1) {
        printf("Tim thay gia tri tuyen tinh.\n", linearIndex);
    } else {
        printf("Khong tim thay gia tri tuyen tinh.\n");
    }
    int biranyIndex = binarySearch(birany, 0, sizeof(birany) / sizeof(birany[0]) - 1, x);
    if (biranyIndex != -1) {
        printf("Tim thay gia tri nhi phan.\n", biranyIndex);
    } else {
        printf("Khong tim thay gia tri nhi phan.\n");
    }
    return 0;
}