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



    Rgb **arr = malloc(bmih.height*sizeof(Rgb*));

    char* color = "black";

    drawLine(300, 440, 562, 500, arr, color, 200, &bmih, &bmfh, f);
    cropping(0,0,500, 200, arr, &bmih, &bmfh, f);
    drawLine(300, 440, 562, 500, arr, color, 200, &bmih, &bmfh, f);
    inversion1(300, 60, 200, arr, &bmih, &bmfh, f);
    drawLine(0, 0, 562, 500, arr, "pink", 200, &bmih, &bmfh, f);
    drawLine(0, 10000, 562, 0, arr, "purple", 100, &bmih, &bmfh, f);

    printf("\n");
    printFileHeader(bmfh);
    printInfoHeader(bmih);
    free(arr);


    return 0;
}