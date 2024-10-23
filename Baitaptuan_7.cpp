#include <stdio.h>

struct Danso  {
    int nam;
    int nguoi;
};

int main() {
    struct Danso data[100];
    int nam, min, max;
    printf("Nhap so nam: ");
    scanf("%d", &nam);
    for (int i = 0; i < nam; i++) {
        data[i].nam = 1920 + i;
        printf("Nhap so luong nguoi sinh ra nam %d: ", data[i].nam);
        scanf("%d", &data[i].nguoi);
    }
    min = max = data[0].nguoi;
    for (int i = 1; i < nam; i++) {
        if (data[i].nguoi < min) {
            min = data[i].nguoi;
        }
        if (data[i].nguoi > max) {
            max = data[i].nguoi;
        }
    }
    printf("Cac nam co cung so luong nguoi sinh ra:\n");
    for (int i = 0; i < nam; i++) {
        for (int j = i + 1; j < nam; j++) {
            if (data[i].nguoi == data[j].nguoi) {
                printf("Nam %d và nam %d: %d nguoi\n", data[i].nam, data[j].nam, data[i].nguoi);
            }
        }
    }
    printf("Nam co so luong nguoi sinh ra it nhat (%d): ", min);
    for (int i = 0; i < nam; i++) {
        if (data[i].nguoi == min) {
            printf("%d ", data[i].nam);
        }
    }
    printf("\n");

    printf("Nam co so luong nguoi sinh ra nhieu nhat (%d): ", max);
    for (int i = 0; i < nam; i++) {
        if (data[i].nguoi == max) {
            printf("%d ", data[i].nam);
        }
    }
    printf("\n");

    return 0;
}

