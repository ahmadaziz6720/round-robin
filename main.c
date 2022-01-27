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
    int jumlah_antrian=0;
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
    int antrian[n+1];
    for (int i=0; i<=n; ++i){
        antrian[i]=0;
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

    printf("\n\n");

    int depan = 0;

    /*Ngerjain satu kuantum*/
    while(antrian[depan]!=9999){
        while(diproses[antrian[depan]]<=kuantum){
            /*jika clock bertepatan dengan waktu kedatangan maka print kedatangan proses*/
            ++diproses[antrian[depan]];

            /*Terdapat proses baru masuk*/
            if (clock==kedatangan[urutan_kedatangan]){
                /*Tambahin ke array antrian dan kita print*/
                antrian[urutan_kedatangan]=urutan_kedatangan;
                for(int i=0; i<=jumlah_antrian; ++i){
                    printf("%d", clock); printf("  "); printf("%d", antrian[i]); printf("  ini kedatangan");
                }
                antrian[urutan_kedatangan]=urutan_kedatangan;
                ++urutan_kedatangan;
                ++jumlah_antrian;
            }

            /*jika sudah selesai kita tandai dengan nilai 9999*/
            if (diproses[antrian[depan]] == waktu[antrian[depan]]){
                diproses[antrian[depan]] = 9999;
                antrian[depan]=0; antrian[jumlah_antrian]=9999;

                /*Menggeser antrian*/
                for(int i=1; i<=jumlah_antrian+1; ++i){
                    antrian[i-1]=antrian[i];
                }
                /*Print*/
                for(int i=0; i<=jumlah_antrian; ++i){
                    printf("%d", clock); printf("  "); printf("%d", antrian[i]);
                }
            }
            ++clock;
        }
        printf("P"); printf("%d", antrian[depan]);
        ++clock;
    }
    printf("\n\nSelesai");
    return 0;
}
