#include <stdio.h>

// Fonksiyon: Konvolüyon işlemi yapan bir fonksiyon
double convolution(int G[4][7], int F[3][3], int x, int y) {
    double sum = 0;
    int filter_sum = 0;

    // Filtre ve görüntü matrisini kaydırarak elemanları çarp ve topla
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += G[x + i][y + j] * F[i][j];
            filter_sum += F[i][j]; // Filtredeki elemanların toplamını hesapla
        }
    }

    return sum / filter_sum; // Toplamı filtre toplamına böl ve sonucu döndür
}

int main() {
    // Gri seviyeli görüntü matrisi G
    int G[4][7] = {
        {0, 1, 2, 0, 1, 2, 0},
        {6, 5, 2, 3, 4, 1, 5},
        {1, 7, 3, 1, 1, 0, 2},
        {1, 2, 3, 4, 0, 1, 2}
    };

    // Filtre matrisi F
    int F[3][3] = {
        {0, 1, 0},
        {2, 3, 1},
        {0, 1, 2}
    };

    // Sonuç matrisinin boyutlarını hesapla
    int result_rows = 2; // M - k + 1
    int result_cols = 2; // N - k + 1
    int R[result_rows][result_cols];

    // Konvolüyon işlemini uygula ve sonucu R matrisine yaz
    for (int i = 0; i < result_rows; i++) {
        for (int j = 0; j < result_cols; j++) {
            R[i][j] = (int)(convolution(G, F, i, j) + 0.5); // Sonucu tam sayıya yuvarlayarak ata
        }
    }

    // Sonuç matrisini yazdır
    printf("Sonuc Matrisi R:\n");
    for (int i = 0; i < result_rows; i++) {
        for (int j = 0; j < result_cols; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Output:
Sonuc Matrisi R:
3 3
4 3
*/
