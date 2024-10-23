//Bai 1: 
#include <stdio.h>
#include <string.h>

void SX(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int x = arr[i];
        int j = i;

        while (j > 0 && arr[j - 1] > x) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
    }
}
int main() {
    int n;
    printf("Nhap so luong doi tuong: ");
    scanf("%d", &n);
    char mau[n][10];
    int so[n];
    printf("Nhap mau sac: \n");
    for (int i = 0; i < n; i++) {
        scanf("%s", mau[i]);
        if (strcmp(mau[i], "do") == 0) {
            so[i] = 0;
        } else if (strcmp(mau[i], "trang") == 0) {
            so[i] = 1; 
        } else if (strcmp(mau[i], "xanh") == 0) {
            so[i] = 2; 
        } else {
            printf("Mau khong hop le\n");
            return 1;
        }
    }
    SX(so, n);
    printf("Ket qua sap xep: \n");
    for (int i = 0; i < n; i++) {
        if (so[i] == 0) {
            printf("do ");
        } else if (so[i] == 1) {
            printf("trang ");
        } else if (so[i] == 2) {
            printf("xanh ");
        }
    }
    printf("\n");
    return 0;
}
/*Bai 2: 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int soNT(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int soNNT(int x) {
    if (x < 4) return 0;
    int p, q, can = sqrt(x);
    for (p = 2; p <= can; p++) {
        if (x % p == 0) {
            q =x / p;
            if (p % 2 == 1 && q % 2 == 1 && soNT(p) && soNT(q)) {
                return 1;
            }
        }
    }
    return 0;
}

void MangBlum(int N, int** array, int* size) {
    int count = 0;
    *array = (int*)malloc(N * sizeof(int));

    for (int i = 4; i < N; i++) {
        if (soNNT(i)) {
            (*array)[count++] = i;
        }
    }
    *size = count;
}

void TimBlum(int* array, int size, int N) {
    printf("Cac cap so Blum co tong la so Blum nho hon %d:\n", N);
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int sum = array[i] + array[j];
            if (sum < N && soNNT(sum)) {
                printf("(%d, %d)\n", array[i], array[j]);
            }
        }
    }
}

int KTBlum(int* array, int size, int M) {
    for (int i = 0; i < size; i++) {
        if (array[i] == M) return 1;
    }
    return 0;
}

int main() {
    int N, M;
    int* array;
    int size;

    printf("Nhap so N: ");
    scanf("%d", &N);
    
    MangBlum(N, &array, &size);
    TimBlum(array, size, N);

    printf("Nhap so Blum M de kiem tra: ");
    scanf("%d", &M);
    if (KTBlum(array, size, M)) {
        printf("%d ton tai trong mang so Blum.\n", M);
    } else {
        printf("%d khong ton tai trong mang so Blum.\n", M);
    }

    free(array);
    return 0;
} */
