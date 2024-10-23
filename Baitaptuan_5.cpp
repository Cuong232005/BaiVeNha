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
/* Bai 2: 
#include <stdio.h>
#include <math.h>
 
int ktra(int x) {
    if (x <= 1) return 0; 
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0; 
    }
    return 1; 
}

