#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack (push, 1)
typedef struct
{
    unsigned short signature;
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct
{
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPixelsPerMeter;
    unsigned int yPixelsPerMeter;
    unsigned int colorsInColorTable;
    unsigned int importantColorCount;
} BitmapInfoHeader;

typedef struct
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
} Rgb;

#pragma pack(pop)

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
    if (*x1 > 562) {
        *x1 = 562;
    }

    if (*x1 < 0) {
        *x1 = 0;
    }
    if (*x2 > 562) {
        *x2 = 562;
    }
    if (*x2 < 0) {
        *x2 = 0;
    }

    if (*y1 > 779) {
        *y1 = 779;
    }
    if (*y1 < 0) {
        *y1 = 0;
    }
    if (*y2 > 779) {
        *y2 = 779;
    }
    if (*y2 < 0) {
        *y2 = 0;
    }

}
void drawLine(int x1, int y1, int x2, int y2, Rgb **arr, char* color, int
thickness){
    int deltaT = 1;
    valid(&x1, &y1, &x2, &y2);
    const int x_1 = x1, x_2 = x2, y_1 = y1, y_2 = y2;
    while(thickness != 0){
        const int deltaX = abs(x2 - x1);
        const int deltaY = abs(y2 - y1);
        const int signX = x1 < x2 ? 1 : -1;
        const int signY = y1 < y2 ? 1 : -1;
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

        arr[x2][y2] = cur;
        while (x1 != x2 || y1 != y2) {
            arr[x1][y1] = cur;
            const int error2 = error * 2;
            //
            if (error2 > -deltaY) {
                error -= deltaY;
                x1 += signX;
            }
            if (error2 < deltaX) {
                error += deltaX;
                y1 += signY;
            }
        }
        thickness--;
        x1 = x_1;
        x2 = x_2;
        y1 = y_1;
        y2 = y_2;
        if (deltaT > 0){

            y1 = y_1 + deltaT;
            y2 = y_2 + deltaT;
            if ( y1 > 779 || y2 >779){
                x2 = x_2 - deltaT;
            }
            if (y1 < 0 || y2 < 0){
                x2 = x_2 + deltaT;
            }

        }
        if (deltaT < 0){
            y1 = y_1 + deltaT;
            y2 = y_2 + deltaT;
            if (y1 > 779 || y2 >779){
                x2 = x_2 + deltaT;
                x1 = x_1 + deltaT;
            }
            if (y1 < 0 || y2 < 0){
                x2 = x_2 - deltaT;
                x1 = x_1 - deltaT;
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
    drawLine(1000, 0, 0, 1000, arr, color, 100);
    //drawLine(0, 779, 562, 0, arr, color, 5);
    for(int i=0; i<H; i++){
        fwrite(arr[i],1,w,ff);
    }
    fclose(ff);

    printf("\n");


    return 0;
}