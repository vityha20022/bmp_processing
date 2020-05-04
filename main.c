#include <stdio.h>
#include <stdlib.h>
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include "Rgb.h"
#include "valid_coor.h"
#include "printFileHeader.h"
#include "printInfoHeader.h"
#include "angle.h"
#include "drawLine.h"





int main(){
    FILE *f = fopen("simpsonsvr.bmp", "rb");
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;
    fread(&bmfh,1,sizeof(BitmapFileHeader),f);
    fread(&bmih, 1, sizeof(BitmapInfoHeader), f);
    printFileHeader(bmfh);
    printInfoHeader(bmih);

    unsigned int H = bmih.height;
    unsigned int W = bmih.width;

    Rgb **arr = malloc(H*sizeof(Rgb*));
    for(int i=0; i<H; i++){
        arr[i] = malloc(W * sizeof(Rgb) + (W*3)%4);
        fread(arr[i],1,W * sizeof(Rgb) + (W*3)%4,f);
    }



    FILE *ff = fopen("out.bmp", "wb");

    bmih.height = H;
    bmih.width = W;
    fwrite(&bmfh, 1, sizeof(BitmapFileHeader),ff);
    fwrite(&bmih, 1, sizeof(BitmapInfoHeader), ff);
    unsigned int w = W * sizeof(Rgb) + (W*3)%4;
    char* color = "black";
    drawLine(400, -110, 400, 111110, arr, &bmih, color, 10);
    printf("%f", angle(0, 10, 0, 0));
    //drawLine(100, 0, 562, 500, arr, color, 500);
    for(int i=0; i<H; i++){
        fwrite(arr[i],1,w,ff);
    }
    fclose(ff);

    printf("\n");


    return 0;
}