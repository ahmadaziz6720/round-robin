#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KAMUS*/
    int kuantum;        /*nilai kuantum*/
    int c_kuantum;      /*counter kuantum*/
    int clock;          /*counter clock*/
    int n;              /*jumlah data*/
    int jumlah_antrian = 1;  /*jumlah antrian dalam antrian*/

    /*ALGORITMA*/
    printf("------------------------------ROUND ROBIN ALGORITHM---------------------------------\n");
    printf("Masukkan nilai kuantum: ");
    scanf("%d", &kuantum);
    printf("Masukkan banyaknya data: ");
    scanf("%d", &n);
    printf("\n");

    /*INISIASI ARRAY DATA*/
    /*{[P],[kedatangan],[lama],[terproses]}*/
    int antrian[100][4] = {
    {0, 0, 0, 0}   /*  initializers for row indexed by 0 */
    };

    /*MENGISI NILAI PROSES*/
    for (int i=0; i<=n-1; ++i){
        antrian[i][0]=i;
    }

    /*Isi tabel lama waktu kedatangan*/
    printf("Masukkan tabel data kedatangan:\n\n");
    printf("| Proses | Kedatangan |\n");
    printf("|--------|------------|\n");
    for (int i=0; i<=n-1; ++i){
        printf("|   P"); printf("%d", antrian[i][0]);
        printf("   |    ");
        scanf("%d", &antrian[i][1]);
    }
    printf("\n");

    /*Isi tabel lama waktu eksekusi*/
    printf("Masukkan tabel data waktu lama eksekusi:\n\n");
    printf("| Proses | Kedatangan | waktu |\n");
    printf("|--------|------------|-------|\n");
    for (int i=0; i<=n-1; ++i){
        printf("|   P"); printf("%d", antrian[i][0]);
        printf("   |    "); printf("%d", antrian[i][1]); printf("     |   ");
        scanf("%d", &antrian[i][2]);
    }

    /*PRINT TABEL DATA ANTRIAN*/
    for (int i=0; i<=n-1; ++i){
        for (int j=0; j<=3; ++j){
            printf("|"); printf("%d", antrian[i][j]); printf("|");
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");


    /*ALGORITMA ROUND ROBIN*/
    /*{[P],[kedatangan],[lama],[terproses]}*/

    /*PENGULANGAN SELAMA SATU KUANTUM*/
    while (jumlah_antrian>0){
        while (c_kuantum<=kuantum){
            /*JIKA ADA YANG BARU DATANG*/
            if (clock==antrian[jumlah_antrian][1]){ /*clock == waktu kedatangan*/
                /*masukin antrian dan print*/
                for(int i=0; i<=jumlah_antrian-1; ++i){
                    printf(" | P%d", antrian[i][0], " |");
                }
                printf("| %d", clock);
                printf("\n");
                jumlah_antrian +=1;
            };

            /*JIKA PROSES SELESAI*/
            if (antrian[0][3]==antrian[0][2]){
                for(int j=0; j<=3; ++j){
                        antrian[jumlah_antrian][j]=antrian[0][j];
                    }
                for(int i=0; i<=jumlah_antrian-1; ++i){
                    for(int j=0; j<=3; ++j){
                        antrian[i][j]=antrian[i+1][j];
                    }
                }
                for(int i=0; i<=jumlah_antrian-1; ++i){
                    printf(" | P%d", antrian[i][0], " |");
                }
                printf("| %d", clock);
                printf("\n");
                jumlah_antrian-=1;
            };
            antrian[0][3] += 1;
            clock += 1;
            c_kuantum+=1;
        };
        c_kuantum=0;
        /*GESER ANTRIAN*/
        for(int j=0; j<=3; ++j){
            antrian[jumlah_antrian][j]=antrian[0][j];
        }
        for(int i=0; i<=jumlah_antrian; ++i){
            for(int j=0; j<=3; ++j){
                antrian[i][j]=antrian[i+1][j];
            }
        }
        for(int i=0; i<=jumlah_antrian-1; ++i){
            printf(" | P%d", antrian[i][0], " |");
        }
        printf("| %d", clock);
    }
    printf("\n");
    printf("\n");
    /*PRINT TABEL DATA ANTRIAN*/
    for (int i=0; i<=n-1; ++i){
        for (int j=0; j<=3; ++j){
            printf("|"); printf("%d", antrian[i][j]); printf("|");
        }
        printf("\n");
    }
    return 0;
}
