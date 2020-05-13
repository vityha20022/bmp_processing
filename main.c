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
#include "getopt.h"
#include "string.h"




int main(int argc, char** argv){
    int image_index = 0;
    for (int i = 0; i < argc; i++){
        if (strstr(argv[i], ".bmp")){
            image_index = i;
        }
    }
    FILE *f = fopen(argv[image_index], "rb");
    if (!f){
        printf("can't open file");
        return 0;
    }
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;
    fread(&bmfh,1,sizeof(BitmapFileHeader),f);
    fread(&bmih, 1, sizeof(BitmapInfoHeader), f);
    if (bmih.headerSize != 40 || bmih.bitsPerPixel != 24){
        printf("This BMP file format is not defined");
        return 0;
    }
    /*printFileHeader(bmfh);
    printInfoHeader(bmih);
    */


    Rgb **arr = calloc(bmih.height*sizeof(Rgb*), 1);

    char* color = "black";
    int opt;
    char* opts = "l:i:I:?";
    struct option longOpts[] = {
            {"inv_1", required_argument, NULL, 'i'},
            {"inv_2", required_argument, NULL, 'i'},
            {"line", required_argument, NULL, 'l'},
            {NULL, 0, NULL, 0}
    };
    int longIndex;
    opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    typedef struct{
        int x1, y1, x2, y2, thickness;
        char* color;
    }DrawLine;

    typedef struct{
        int x0, y0, radius;
    }inv1;

    typedef struct{
        int x1, y1, x2, y2;
    }inv2;


    DrawLine draw;
    inv1 inv_1;
    inv2 inv_2;
    char* endptr;
    int index;
    char *arr_color[] = {"red", "green", "pink", "orange", "blue",
                         "purple", "black", "white", "brown"};
    while(opt != -1){
        switch (opt) {
            case 'l':
                index = optind - 1;
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.x1 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument x1 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.y1 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument y1 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.x2 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument x2 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.y2 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument y2 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.thickness = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument thickness should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                draw.color = argv[index];
                int color = 0;
                for (int i = 0; i < 9; i++) {
                    if (!strcmp(arr_color[i], draw.color)){
                        color = 1;
                    }
                }
                if (!color){
                    fprintf(stderr, "this color is not in the color list");
                    return 0;
                }
                drawLine(draw.x1, draw.y1, draw.x2, draw.y2, arr, draw.color, draw.thickness, &bmih, &bmfh, f);
                optind = index - 1;
                break;
            case 'i':
                index = optind - 1;
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])){
                    inv_1.x0 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument x0 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_1.y0 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument y0 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_1.radius = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument radius should be type int");
                    return 0;
                }
                inversion1(inv_1.x0, inv_1.y0, inv_1.radius, arr, &bmih, &bmfh, f);
                optind = index - 1;
                break;

            case 'I':
                index = optind - 1;
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_2.x1 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument x1 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_2.y1 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument y1 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_2.x2 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument x2 should be type int");
                    return 0;
                }
                index++;
                if (index >= argc){
                    fprintf(stderr, "arguments are not enough");
                    return 0;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_2.y2 = atoi(argv[index]);
                } else {
                    fprintf(stderr, "the argument y2 should be type int");
                    return 0;
                }
                inversion2(inv_2.x1, inv_2.y1, inv_2.x2, inv_2.y2, arr, &bmih, &bmfh, f);
                optind = index - 1;
                break;




            case '?':
                printf("\nWHAAAAAAAAAAAT????\n");
                break;
        }
        opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    }
    for(int k = 0; k < argc; k++){
        printf("[%s]\n", argv[k]);
    }




    //cropping(0, 0, 256, 256, arr, &bmih, &bmfh, f);

    printf("\n");
    free(arr);


    return 0;
}