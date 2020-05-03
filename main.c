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
    BitmapInfoHeader bmif;
    fread(&bmfh,1,sizeof(BitmapFileHeader),f);
    fread(&bmif,1,sizeof(BitmapInfoHeader),f);
    printFileHeader(bmfh);
    printInfoHeader(bmif);

    unsigned int H = bmif.height;
    unsigned int W = bmif.width;

    Rgb **arr = malloc(H*sizeof(Rgb*));
    for(int i=0; i<H; i++){
        arr[i] = malloc(W * sizeof(Rgb) + (W*3)%4);
        fread(arr[i],1,W * sizeof(Rgb) + (W*3)%4,f);
    }



    FILE *ff = fopen("out.bmp", "wb");

    bmif.height = H;
    bmif.width = W;
    fwrite(&bmfh, 1, sizeof(BitmapFileHeader),ff);
    fwrite(&bmif, 1, sizeof(BitmapInfoHeader),ff);
    unsigned int w = W * sizeof(Rgb) + (W*3)%4;
    char* color = "green";
    drawLine(0, 220, 255, 690, arr, color, 210);
    printf("%f", angle(0, 220, 255, 690));
    //drawLine(100, 0, 562, 500, arr, color, 5);
    for(int i=0; i<H; i++){
        fwrite(arr[i],1,w,ff);
    }
    fclose(ff);

    printf("\n");


    return 0;
}