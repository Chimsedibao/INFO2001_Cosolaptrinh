#include <stdio.h>
#include <string.h>
#include <algorithm>

struct Student {
    char name[50];
    int id;
    float grade;
};

void swap(struct Student s[], int j, int j1) {
    struct Student temp = s[j];
    s[j] = s[j1];
    s[j1] = temp;
}

void bubblesort(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].grade > s[j + 1].grade) {
                swap(s, j, j + 1);
            }
        }
    }
}

void linearsearch(struct Student s[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (s[i].id == x) {
            printf("Found Ten: %s, ID: %d, Diem Ly: %.2f\n", s[i].name, s[i].id, s[i].grade);
            return;
        }
    }
    printf("Khong tim thay sinh vien co ID %d.\n", x);
}

void updateStudent(struct Student s[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (s[i].id == x) {
            printf("Nhap thong tin moi cho sinh vien co ID %d:\n", x);
            printf("Nhap ho ten moi: ");
            fgets(s[i].name, sizeof(s[i].name), stdin);
            s[i].name[strcspn(s[i].name, "\n")] = '\0';
            printf("Nhap diem Ly moi: ");
            scanf("%f", &s[i].grade);
            printf("Thong tin sinh vien sau khi cap nhat:\n");
            printf("Ten: %s, ID: %d, Diem Ly: %.2f\n", s[i].name, s[i].id, s[i].grade);
            return;
        }
    }
    printf("Khong tim thay sinh vien co ID %d de cap nhat.\n", x);
}

int main() {
    int n, x;
    do {
        printf("So sinh vien trong lop la: ");
        scanf("%d", &n);
    } while (n < 0 || n > 100);

    while (getchar() != '\n');

    struct Student s[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap ho ten sinh vien thu %d: ", i + 1);
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';
        printf("Nhap ID sv %d: ", i + 1);
    
        scanf("%d", &s[i].id);

        // Thêm ki?m tra h?p l? cho ID
        while (s[i].id < 0) {
            printf("ID khong hop le. Nhap lai ID sv %d: ", i + 1);
            scanf("%d", &s[i].id);
        }

        printf("Nhap diem Ly sinh vien thu %d: ", i + 1);
        scanf("%f", &s[i].grade);
        while (getchar() != '\n');
    }

    bubblesort(s, n);

    printf("\nDanh sach sinh vien sau khi sap xep theo diem Ly:\n");
    for (int i = 0; i < n; i++) {
        printf("Ten: %s, ID: %d, Diem Ly: %.2f\n", s[i].name, s[i].id, s[i].grade);
    }
    printf("Nhap so ID can tim: ");
    scanf("%d", &x);

    linearsearch(s, n, x);
    updateStudent(s, n, x);

    return 0;
}

