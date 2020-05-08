#include <stdio.h>
#include <stdlib.h>
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include "Rgb.h"
#include "validCoorFirst.h"
#include "printFileHeader.h"
#include "printInfoHeader.h"
#include "angle.h"
#include "drawLine.h"
#include "drawCircle.h"





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
    //drawLine(0, 1000, 0, 562, arr, &bmih, color, 100);
    printf("%f", angle(300, 1000, 300, -1000, &bmih));
    //drawLine(300, 440, 562, 500, arr, &bmih, color, 200);
    drawCircle(-1400, 1600, 500, arr, &bmih, color);

    for(int i = 0; i<H; i++){
        fwrite(arr[i],1,w,ff);
    }
    fclose(ff);

    printf("\n");


    return 0;
}