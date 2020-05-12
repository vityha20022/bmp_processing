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
    FILE *f = fopen("bar.bmp", "rb");
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;
    fread(&bmfh,1,sizeof(BitmapFileHeader),f);
    fread(&bmih, 1, sizeof(BitmapInfoHeader), f);
    if (bmih.headerSize != 40 || bmih.bitsPerPixel != 24){
        printf("This BMP file format is not defined");
        return 0;
    }
    printFileHeader(bmfh);
    printInfoHeader(bmih);



    Rgb **arr = calloc(bmih.height*sizeof(Rgb*), 1);

    char* color = "black";

    drawLine(0, 0, 156, 256, arr, color, 200, &bmih, &bmfh, f);
    inversion1(100, 100, 1000, arr, &bmih, &bmfh, f);
    inversion2(2000, 2000, 3000, 3000, arr, &bmih, &bmfh, f);
    cropping(0, 0, 256, 128, arr, &bmih, &bmfh, f);

    printf("\n");
    printFileHeader(bmfh);
    printInfoHeader(bmih);
    free(arr);


    return 0;
}