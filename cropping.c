#include <bits/types/FILE.h>
#include "cropping.h"
#include "stdio.h"
#include "validCoorFirst.h"
#include "stdlib.h"


void cropping(int x1, int y1, int x2, int y2, Rgb **arr, BitmapInfoHeader* bmih, BitmapFileHeader* bmfh, FILE *f){
    validCoorFirst(&x1, &y1, &x2, &y2, bmih);
    if (x1 >= x2 || y1 <= y2){
        printf("you entered invalid coordinates");
        return;
    }
    int w1;
    if ((x2 - x1) * sizeof(Rgb) % 4 != 0) {
        w1 = (x2 - x1) * sizeof(Rgb) + (4 - (((x2 - x1) * 3) % 4));
    } else{
        w1 = (x2 - x1) * sizeof(Rgb);
    }
    unsigned int H = (y1 - y2);
    unsigned int W = (x2 - x1);
    int w2 = ((int)bmih -> width - x1) * sizeof(Rgb) + (((int)bmih -> width * 3) % 4);
    char* buf;
    for (int k = 0; k < y2; k++){
        arr[k] = malloc(bmih -> width * sizeof(Rgb) + ((bmih -> width * 3) % 4));
        buf = malloc(bmih -> width * sizeof(Rgb) + ((bmih -> width * 3) % 4));
        fread(buf, 1, bmih -> width * sizeof(Rgb) + ((bmih -> width * 3) % 4), f);
        free(buf);
    }
    for(int i = 0; i < H; i++){
        arr[i] = malloc(w2);
        buf = malloc(w2);
        fread(buf, 1, x1 * 3, f);
        fread(arr[i], 1, w2, f);
        free(buf);
    }


    FILE *out_file = fopen("out.bmp", "wb");
    bmih -> width = W;
    bmih -> height = H;
    fwrite(bmfh, 1, sizeof(BitmapFileHeader),out_file);
    fwrite(bmih, 1, sizeof(BitmapInfoHeader), out_file);
    for (int i = 0; i < H; i++){
        fwrite(arr[i], 1,w1, out_file);
    }
    fclose(out_file);





}