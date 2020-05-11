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
#include "inversion1.h"
#include "inversion2.h"
#include "cropping.h"




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
    /*for(int i=0; i<H; i++){
        arr[i] = malloc(W * sizeof(Rgb) + (W*3)%4);
        fread(arr[i],1,W * sizeof(Rgb) + (W*3)%4,f);
    }*/



    //FILE *ff = fopen("out.bmp", "wb");


    unsigned int w = W * sizeof(Rgb) + (W * 3)%4;
    char* color = "black";
    char* buf = malloc(1000 * 10);
    //drawLine(0, 1000, 0, 562, arr, &bmih, color, 100);
    //drawLine(300, 440, 562, 500, arr, &bmih, color, 200);
    //inversion1(-1400, 1600, 500, arr, &bmih);
    //inversion2(500, 532, 600, 632, arr, &bmih);
    /*for(int i=0; i < 100; i++){
        arr[i] = malloc(w);
        fread(buf, 1, 0, f);
        fread(arr[i],1,w,f);
    }

    int w1 = (W - 680) * sizeof(Rgb) + ((W - 680)*3)%4;
    for(int i = 0; i < 100; i++){
        fwrite(arr[i],1,w1,ff);
    }*/
    //fwrite(&bmfh, 1, sizeof(BitmapFileHeader),ff);
    //fwrite(&bmih, 1, sizeof(BitmapInfoHeader), ff);
    //cropping(0,0,500, 500, arr, &bmih, &bmfh, f);
    //inversion2(0, 0, 200, 200, arr, &bmih, &bmfh, f);
    inversion1(100, 100, 200, arr, &bmih);
    //cropping(0,0,1000, 4200, arr, &bmih, &bmfh, f);
    //cropping(0,0,200, 200, arr, &bmih, &bmfh, f);
    //cropping(-100, -100, 150, 150, arr, &bmih, &bmfh, f);


    //fclose(ff);
    printf("\n");


    return 0;
}