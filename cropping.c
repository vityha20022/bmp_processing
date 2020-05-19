#include "cropping.h"
#include "stdio.h"
#include "validCoorFirst.h"
#include "stdlib.h"

void cropping(int x1, int y1, int x2, int y2, Rgb **arr, BitmapInfoHeader* bmih, BitmapFileHeader* bmfh, FILE *f, char *name_out){
    // валидация координат в пределы изображения
    validCoorFirst(&x1, &y1, &x2, &y2, bmih);
    // массив для заполнения выравнивания нулями
    int array[1] = {0};

    if (x1 >= x2 || y1 <= y2){
        printf("func crop: you entered invalid coordinates\n");
        return;
    }
    // переменная для считывания итоговой строки
    int w1 = 0;
    w1 = (x2 - x1) * sizeof(Rgb);
    // выравнивание для итоговой строки
    int w1_padding = 0;
    w1_padding = (4 - (((x2 - x1) * 3) % 4));
    // новая высота изображения
    unsigned int H = (y1 - y2);
    // новая длина изображения
    unsigned int W = (x2 - x1);


    // переменная для считывания всей строки
    int w3 = 0;
    if ((int)bmih -> width * sizeof(Rgb) % 4 != 0){
        w3 = ((int)bmih -> width * sizeof(Rgb) + (4 - ((int)bmih -> width * 3) % 4 ));
    } else{
        w3 = (int)bmih -> width * sizeof(Rgb);
    }
    // обрезаем строки снизу
    fseek(f, y2 * w3, SEEK_CUR);
    // заполняем массив arr строками обрезанными слева
    for(int i = 0; i < H; i++){
        arr[i] = calloc(w3 - (x1 * 3), 1);
        fseek(f, x1 * 3, SEEK_CUR);
        fread(arr[i], 1, w3 - (x1 * 3), f);
    }


    FILE *out_file = fopen(name_out, "wb");
    bmih -> width = W;
    bmih -> height = H;
    bmfh -> filesize = (H * W * sizeof(Rgb)) + sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    fwrite(bmfh, 1, sizeof(BitmapFileHeader),out_file);
    fwrite(bmih, 1, sizeof(BitmapInfoHeader), out_file);
    // записываем в выходной файл строки обрезанные справа
    for (int i = 0; i < H; i++){
        fwrite(arr[i], 1, w1, out_file);
        if (w1 % 4 != 0){
            fwrite(array, 1, w1_padding, out_file);
        }
    }
    fclose(f);
    // очищаем память
    for(int i = 0; i < H; i++){
        free(arr[i]);
    }

    f = fopen(name_out, "rb");
    fread(bmfh,1,sizeof(BitmapFileHeader),f);
    fread(bmih, 1, sizeof(BitmapInfoHeader), f);
    fclose(out_file);

}