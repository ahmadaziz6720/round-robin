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

    /*Isi tabel lama waktu kedatangan*/
    printf("Masukkan tabel data kedatangan:\n\n");
    printf("| Proses | Kedatangan |\n");
    printf("|--------|------------|\n");
    for (int i=0; i<=n; ++i){
        printf("|   P2   |    "); scanf("%d", &kedatangan[i]);
    }
    printf("\n");
    /*Isi tabel lama waktu eksekusi*/
    printf("Masukkan tabel data waktu lama eksekusi:\n\n");
    printf("| Proses | Kedatangan | waktu |\n");
    printf("|--------|------------|-------|\n");
    for (int i=0; i<=n; ++i){
        printf("|   P2   |    "); printf("%d", kedatangan[i]); printf("     |   ");
        scanf("%d", &waktu[i]);
    }
    return 0;
}
