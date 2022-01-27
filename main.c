#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KAMUS*/
    int kuantum;
    int max_data = 100;
    int kedatangan[max_data];
    int waktu[max_data];
    int n;


    /*ALGORITMA*/
    printf("------------------------------ROUND ROBIN ALGORITHM---------------------------------\n");
    printf("Masukkan nilai kuantum: ");
    scanf("%d", &kuantum);
    printf("Masukkan banyaknya data: ");
    scanf("%d", &n);
    printf("\n");
    printf("Masukkan tabel data kedatangan dan eksekusi:\n\n");
    printf("| Proses | Kedatangan |\n");
    printf("|--------|------------|\n");
    printf("|   P1   |    100     |   50  |\n");
    printf("|   P2   |    150     |  200  |\n");
    printf("|   P2   |    "); scanf("%d", &kedatangan[1]);
    printf(kedatangan[1]);

    return 0;
}
