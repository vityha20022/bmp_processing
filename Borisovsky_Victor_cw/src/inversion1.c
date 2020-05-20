#include "inversion1.h"
#include <stdlib.h>
#include <stdio.h>

void inversion1(int x0, int y0, int radius, Rgb **arr, BitmapInfoHeader *bmih, BitmapFileHeader *bmfh, FILE *f, char *name_out){
    // валидация игрик координаты
    y0 = (int)(bmih -> height - 1) - y0;
    // массив для заполнения выравнивания 0
    int array[1] = {0};
    int W = 0;
    // размер строки
    W = (int)bmih -> width * sizeof(Rgb);
    int W_Padding = 0;
    // размер выравнивания
    W_Padding = (4 - ((int)bmih -> width * 3) % 4);
    // заполнение массива пикселей
    for (int k = 0; k < bmih -> height; k++){
        arr[k] = calloc(W, 1);
        fread(arr[k],1, W, f);
        if (W % 4 != 0){
            fseek(f, W_Padding, SEEK_CUR);
        }
    }
    int dx = 0;
    int dy = 0;
    // координаты квадрата в который вписана окружность
    int square_coord_x = x0 - radius;
    int square_coord_y = y0 - radius;
    // проходимся по всему квадрату, если расстояние от точки до центра меньше радиуса - инвертируем
    for (int i = 0; i < 2 * radius; i++){
        for (int j = 0; j < 2 * radius; j++){
            dx = x0 - square_coord_x;
            dy = y0 - square_coord_y;
            if ((dx * dx + dy * dy) < (radius * radius) && (square_coord_x < (int)bmih -> width && square_coord_x >= 0 && square_coord_y >= 0 && square_coord_y < (int)bmih -> height)){
                arr[square_coord_y][square_coord_x].r = ~arr[square_coord_y][square_coord_x].r;
                arr[square_coord_y][square_coord_x].g = ~arr[square_coord_y][square_coord_x].g;
                arr[square_coord_y][square_coord_x].b = ~arr[square_coord_y][square_coord_x].b;
            }

            square_coord_y++;
        }
        square_coord_y = y0 - radius;
        square_coord_x++;
    }
    // записываем измененный массив в новый файл
    FILE *out_file = fopen(name_out, "wb");
    fwrite(bmfh, 1, sizeof(BitmapFileHeader),out_file);
    fwrite(bmih, 1, sizeof(BitmapInfoHeader), out_file);
    for (int i = 0; i < bmih -> height; i++){
        fwrite(arr[i], 1,W, out_file);
        if (W % 4 != 0){
            fwrite(array, 1, W_Padding, out_file);
        }
    }
    fclose(f);
    for (int k = 0; k < bmih -> height; k++){
        free(arr[k]);
    }
    f = fopen(name_out, "rb");
    fread(bmfh,1,sizeof(BitmapFileHeader),f);
    fread(bmih, 1, sizeof(BitmapInfoHeader), f);
    fclose(out_file);


}


