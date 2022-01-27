#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KAMUS*/
    int kuantum;
    int max_data = 100;
    int kedatangan[max_data];
    int waktu[max_data];
    int diproses[max_data];
    int clock=0;
    int urutan_kedatangan=0;
    int n;


    /*ALGORITMA*/
    printf("------------------------------ROUND ROBIN ALGORITHM---------------------------------\n");
    printf("Masukkan nilai kuantum: ");
    scanf("%d", &kuantum);
    printf("Masukkan banyaknya data: ");
    scanf("%d", &n);
    n -= 1;
    printf("\n");

    /*Membuat array antrian eksekusi*/
    int antrian[n];
    for (int i=0; i<=n; ++i){
        antrian[i]=i;
    }

    /*Isi tabel lama waktu kedatangan*/
    printf("Masukkan tabel data kedatangan:\n\n");
    printf("| Proses | Kedatangan |\n");
    printf("|--------|------------|\n");
    for (int i=0; i<=n; ++i){
        printf("|   P"); printf("%d", antrian[i]); printf("   |    "); scanf("%d", &kedatangan[i]);
    }
    printf("\n");

    /*Isi tabel lama waktu eksekusi*/
    printf("Masukkan tabel data waktu lama eksekusi:\n\n");
    printf("| Proses | Kedatangan | waktu |\n");
    printf("|--------|------------|-------|\n");
    for (int i=0; i<=n; ++i){
        printf("|   P"); printf("%d", antrian[i]); printf("   |    "); printf("%d", kedatangan[i]); printf("     |   ");
        scanf("%d", &waktu[i]);
        diproses[i] = 0;
    }

    int depan = 0;

    /*Ngerjain satu kuantum*/
    while(antrian[depan]!=9999){
        while(diproses[antrian[depan]]<=kuantum){
            /*jika clock bertepatan dengan waktu kedatangan maka print kedatangan proses*/
            ++diproses[antrian[depan]];

            /*Terdapat proses baru masuk*/
            if (clock==kedatangan[urutan_kedatangan]){
                /*Tambahin ke array antrian dan kita print*/
                printf("|  %d", clock); printf("  |  P%d",antrian[urutan_kedatangan] );
                ++urutan_kedatangan;
            }

            /*jika sudah selesai kita tandai dengan nilai 9999*/
            if (diproses[antrian[depan]] == waktu[antrian[depan]]){
                diproses[antrian[depan]] = 9999;
            }
            ++clock;
        }
        printf("P"); printf("%d", antrian[depan]);
        ++clock;
    }
    return 0;
}
