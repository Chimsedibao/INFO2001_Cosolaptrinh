#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

typedef struct Nhanvien {
    int ID;
    char name[50];
    char position[50];
    float salary;
} NV;

int addEmployee(NV employees[], int n) {
    if (n < MAX_EMPLOYEES) {
        printf("Nhap thong tin nhan vien:\n");

        printf("Ma nhan vien: ");
        scanf("%d", &employees[n].ID);

        printf("Ho ten: ");
        while (getchar() != '\n'); 
        fgets(employees[n].name, sizeof(employees[n].name), stdin);
        employees[n].name[strcspn(employees[n].name, "\n")] = '\0'; 

        printf("Chuc vu: ");
        fgets(employees[n].position, sizeof(employees[n].position), stdin);
        employees[n].position[strcspn(employees[n].position, "\n")] = '\0'; 

        printf("Luong: ");
        scanf("%f", &employees[n].salary);

        printf("Da them nhan vien.\n");
        return n + 1; 
    } else {
        printf("Danh sach nhan vien da day. Khong the them moi.\n");
        return n; 
    }
}

void deleteEmployee(NV employees[], int n) {
    if (n > 0) {
        int employeeID;
        printf("Nhap ma nhan vien can xoa: ");
        scanf("%d", &employeeID);

        int found = 0;

        for (int i = 0; i < n; i++) {
            if (employees[i].ID == employeeID) {
                employees[i] = employees[n - 1];
                n--;
                found = 1;
                printf("Da xoa nhan vien co ma %d.\n", employeeID);
                break;
            }
        }

        if (!found) {
            printf("Khong tim thay nhan vien co ma %d.\n", employeeID);
        }
    } else {
        printf("Danh sach nhan vien trong. Khong co gi de xoa.\n");
    }
}


void displayEmployees(NV employees[], int n) {
    if (n > 0) {
        printf("Danh sach nhan vien:\n");
        for (int i = 0; i < n; i++) {
            printf("Ma: %d, Ho ten: %s, Chuc vu: %s, Luong: %.2f\n",
                   employees[i].ID, employees[i].name,
                   employees[i].position, employees[i].salary);
        }
    } else {
        printf("Danh sach nhan vien trong. Khong co gi de hien thi.\n");
    }
}

void sortEmployees(NV employees[], int n) {
    if (n > 0) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (employees[j].salary < employees[j + 1].salary) {
                    NV temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }

        printf("Da sap xep nhan vien theo muc luong giam dan.\n");
    } else {
        printf("Danh sach nhan vien trong. Khong co gi de sap xep.\n");
    }
}

int main() {
    int n = 0;
    NV employees[MAX_EMPLOYEES];

    int choice;

    do {
        printf("\nQuan Ly Nhan Su\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi nhan vien\n");
        printf("4. Sap xep nhan vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        if (choice == 1) {
            n = addEmployee(employees, n);
        } else if (choice == 2) {
            deleteEmployee(employees, n);
        } else if (choice == 3) {
            displayEmployees(employees, n);
        } else if (choice == 4) {
            sortEmployees(employees, n);
        } else if (choice == 0) {
            printf("Ket thuc chuong trinh.\n");
        } else {
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
