#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include "Rgb.h"








void printFileHeader(BitmapFileHeader header){
    printf("signature:\t%x (%hu)\n", header.signature, header.signature);
    printf("filesize:\t%x (%u)\n", header.filesize, header.filesize);
    printf("reserved1:\t%x (%hu)\n", header.reserved1, header.reserved1);
    printf("reserved2:\t%x (%hu)\n", header.reserved2, header.reserved2);
    printf("pixelArrOffset:\t%x (%u)\n", header.pixelArrOffset, header.pixelArrOffset);
}

void printInfoHeader(BitmapInfoHeader header){
    printf("headerSize:\t%x (%u)\n", header.headerSize, header.headerSize);
    printf("width:     \t%x (%u)\n", header.width, header.width);
    printf("height:    \t%x (%u)\n", header.height, header.height);
    printf("planes:    \t%x (%hu)\n", header.planes, header.planes);
    printf("bitsPerPixel:\t%x (%hu)\n", header.bitsPerPixel, header.bitsPerPixel);
    printf("compression:\t%x (%u)\n", header.compression, header.compression);
    printf("imageSize:\t%x (%u)\n", header.imageSize, header.imageSize);
    printf("xPixelsPerMeter:\t%x (%u)\n", header.xPixelsPerMeter, header.xPixelsPerMeter);
    printf("yPixelsPerMeter:\t%x (%u)\n", header.yPixelsPerMeter, header.yPixelsPerMeter);
    printf("colorsInColorTable:\t%x (%u)\n", header.colorsInColorTable, header.colorsInColorTable);
    printf("importantColorCount:\t%x (%u)\n", header.importantColorCount, header.importantColorCount);
}
void valid(int *x1, int *y1, int *x2, int *y2){
    if (*y1 > 562) {
        *y1 = 562;
    }

    if (*y1 < 0) {
        *y1 = 0;
    }
    if (*y2 > 562) {
        *y2 = 562;
    }
    if (*y2 < 0) {
        *y2 = 0;
    }

    if (*x1 > 779) {
        *x1 = 779;
    }
    if (*x1 < 0) {
        *x1 = 0;
    }
    if (*x2 > 779) {
        *x2 = 779;
    }
    if (*x2 < 0) {
        *x2 = 0;
    }

}

void angle(int x1, int y1, int x2, int y2){
    float A = -(y1 - y2);
    float B = (x2 - x1);
    float k = (A/B);
    float angle = atan(k) * 180 / M_PI;
    if (angle < 0){
        angle += 180;
    }
    printf("%f", angle);


}

void drawLine(int x1, int y1, int x2, int y2, Rgb **arr, char* color, int
thickness){
    int deltaT = 1;
    valid(&x1, &y1, &x2, &y2);
    const int x_1 = x1, x_2 = x2, y_1 = y1, y_2 = y2;
    while(thickness != 0){
        const int deltaX = abs(y2 - y1);
        const int deltaY = abs(x2 - x1);
        const int signX = y1 < y2 ? 1 : -1;
        const int signY = x1 < x2 ? 1 : -1;
        //
        int error = deltaX - deltaY;
        //
        Rgb cur;
        char *arr_color[] = {"red", "green", "pink", "orange", "blue",
                             "purple", "black", "white", "brown"};
        Rgb rgb_arr_color[] = {{0,   0,   255},
                               {0,   128, 0},
                               {203, 192, 255},
                               {0,   165, 255},
                               {255, 0,   0},
                               {128, 0,   128},
                               {0,   0,   0},
                               {255, 255, 255},
                               {42,  42,  165}};

        for (int i = 0; i < 9; i++) {
            if (!strcmp(arr_color[i], color)) {
                cur = rgb_arr_color[i];
            }
        }

        arr[y2][x2] = cur;
        while (y1 != y2 || x1 != x2) {
            arr[y1][x1] = cur;
            const int error2 = error * 2;
            //
            if (error2 > -deltaY) {
                error -= deltaY;
                y1 += signX;
            }
            if (error2 < deltaX) {
                error += deltaX;
                x1 += signY;
            }
        }
        thickness--;
        y1 = y_1;
        y2 = y_2;
        x1 = x_1;
        x2 = x_2;
        if (deltaT > 0){

            x1 = x_1 + deltaT;
            x2 = x_2 + deltaT;
            if (x1 > 779 || x2 > 779){
                y2 = y_2 - deltaT;
            }
            if (x1 < 0 || x2 < 0){
                y2 = y_2 + deltaT;
            }

        }
        if (deltaT < 0){
            x1 = x_1 + deltaT;
            x2 = x_2 + deltaT;
            if (x1 > 779 || x2 > 779){
                y2 = y_2 + deltaT;
                y1 = y_1 + deltaT;
            }
            if (x1 < 0 || x2 < 0){
                y2 = y_2 - deltaT;
                y1 = y_1 - deltaT;
            }
            deltaT--;
        }
        valid(&x1, &y1, &x2, &y2);
        deltaT = -deltaT;


    }

}




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
    drawLine(0, 0, 779, 562, arr, color, 10);
    //angle(200, 200, 200, 300);
    //drawLine(0, 779, 562, 0, arr, color, 5);
    for(int i=0; i<H; i++){
        fwrite(arr[i],1,w,ff);
    }
    fclose(ff);

    printf("\n");


    return 0;
}