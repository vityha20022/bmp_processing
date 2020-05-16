#include "cropping.h"
#include "stdio.h"
#include "validCoorFirst.h"
#include "stdlib.h"

void cropping(int x1, int y1, int x2, int y2, Rgb **arr, BitmapInfoHeader* bmih, BitmapFileHeader* bmfh, FILE *f, char *name_out){
    validCoorFirst(&x1, &y1, &x2, &y2, bmih);
    int w1 = 0;
    if ((x2 - x1) * sizeof(Rgb) % 4 != 0) {
        w1 = (x2 - x1) * sizeof(Rgb) + (4 - (((x2 - x1) * 3) % 4));
    } else{
        w1 = (x2 - x1) * sizeof(Rgb);
    }
    unsigned int H = (y1 - y2);
    unsigned int W = (x2 - x1);

    int w2 = 0;
    if (((int)bmih -> width - x1) * sizeof(Rgb) % 4 != 0) {
        w2 = ((int)bmih -> width - x1) * sizeof(Rgb) + (4 - ((((int)bmih -> width - x1) * 3) % 4));
    } else{
        w2 = (int)(bmih -> width - x1) * sizeof(Rgb);
    }
    int w3 = 0;
    if ((int)bmih -> width * sizeof(Rgb) % 4 != 0){
        w3 = ((int)bmih -> width * sizeof(Rgb) + (4 - ((int)bmih -> width * 3) % 4 ));
    } else{
        w3 = (int)bmih -> width * sizeof(Rgb);
    }

    if (x1 >= x2 || y1 <= y2){
        printf("func crop: you entered invalid coordinates\n");
        return;
    }

    char* buf;
    /*for (int k = 0; k < y2; k++){
        buf = calloc(w3, 1);
        fread(buf, 1, w3, f);
        free(buf);
    }*/
    fseek(f, y2 * w3, SEEK_CUR);
    for(int i = 0; i < H; i++){
        arr[i] = calloc(w2, 1);
        buf = malloc(x1 * 3);
        fread(buf, 1, x1 * 3, f);
        fread(arr[i], 1, w2, f);
        free(buf);
    }


    FILE *out_file = fopen(name_out, "wb");
    bmih -> width = W;
    bmih -> height = H;
    bmfh -> filesize = (H * W * sizeof(Rgb)) + sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    fwrite(bmfh, 1, sizeof(BitmapFileHeader),out_file);
    fwrite(bmih, 1, sizeof(BitmapInfoHeader), out_file);
    for (int i = 0; i < H; i++){
        fwrite(arr[i], 1,w1, out_file);
    }
    fclose(f);
    for(int i = 0; i < H; i++){
        free(arr[i]);
    }
    f = fopen(name_out, "rb");
    fread(bmfh,1,sizeof(BitmapFileHeader),f);
    fread(bmih, 1, sizeof(BitmapInfoHeader), f);
    fclose(out_file);

}