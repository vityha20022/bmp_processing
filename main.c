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
    if (image_index == 0){
        printf("you did not enter a file name");
        return 0;
    }
    FILE *input_file = fopen(argv[image_index], "rb");
    if (!input_file){
        printf("can't open file");
        return 0;
    }
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;
    fread(&bmfh,1,sizeof(BitmapFileHeader), input_file);
    fread(&bmih, 1, sizeof(BitmapInfoHeader), input_file);
    if (bmih.headerSize != 40 || bmih.bitsPerPixel != 24){
        printf("This BMP file format is not defined");
        return 0;
    }
    /*printFileHeader(bmfh);
    printInfoHeader(bmih);
    */
    FILE *f = fopen(argv[image_index], "rb");
    fread(&bmfh,1,sizeof(BitmapFileHeader),f);
    fread(&bmih, 1, sizeof(BitmapInfoHeader), f);
    fclose(input_file);

    Rgb **arr = calloc(bmih.height*sizeof(Rgb*), 1);

    char* color = "black";
    int opt;
    char* opts = "l:i:I:c:h?";
    struct option longOpts[] = {
            {"inv_1", required_argument, NULL, 'i'},
            {"inv_2", required_argument, NULL, 'i'},
            {"line", required_argument, NULL, 'l'},
            {"crop", required_argument, NULL, 'c'},
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
    typedef struct{
        int x1, y1, x2, y2;
    }cr;


    DrawLine draw;
    inv1 inv_1;
    inv2 inv_2;
    cr crop;
    char* endptr;
    int index;

    while(opt != -1){
        switch (opt) {
            case 'l':
                index = optind - 1;
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.x1 = atoi(argv[index]);
                } else {
                    printf("func line: the argument x1 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func line: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.y1 = atoi(argv[index]);
                } else {
                    printf("func line: the argument y1 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func line: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.x2 = atoi(argv[index]);
                } else {
                    printf("func line: the argument x2 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func line: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.y2 = atoi(argv[index]);
                } else {
                    printf("func line: the argument y2 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func line: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    draw.thickness = atoi(argv[index]);
                } else {
                    printf("func line: the argument thickness should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf( "func line: arguments are not enough\n");
                    break;
                }
                draw.color = argv[index];
                drawLine(draw.x1, draw.y1, draw.x2, draw.y2, arr, draw.color, draw.thickness, &bmih, &bmfh, f);
                optind = index - 1;
                break;

            case 'i':
                index = optind - 1;
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])){
                    inv_1.x0 = atoi(argv[index]);
                } else {
                    printf("func inv_1: the argument x0 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf( "func inv_1: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_1.y0 = atoi(argv[index]);
                } else {
                    printf("func inv_1: the argument y0 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf( "func inv_1: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_1.radius = atoi(argv[index]);
                } else {
                    printf("func inv_1: the argument radius should be type int\n");
                    break;
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
                    printf("func inv_2: the argument x1 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func inv_2: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_2.y1 = atoi(argv[index]);
                } else {
                    printf("func inv_2: the argument y1 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func inv_2: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_2.x2 = atoi(argv[index]);
                } else {
                    printf("func inv_2: the argument x2 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func inv_2: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    inv_2.y2 = atoi(argv[index]);
                } else {
                    printf("func inv_2: the argument y2 should be type int\n");
                    break;
                }
                inversion2(inv_2.x1, inv_2.y1, inv_2.x2, inv_2.y2, arr, &bmih, &bmfh, f);
                optind = index - 1;
                break;

            case 'c':
                index = optind - 1;
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    crop.x1 = atoi(argv[index]);
                } else {
                    printf("func crop: the argument x1 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func crop: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    crop.y1 = atoi(argv[index]);
                } else {
                    printf("func crop: the argument y1 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func crop: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    crop.x2 = atoi(argv[index]);
                } else {
                    printf("func crop: the argument x2 should be type int\n");
                    break;
                }
                index++;
                if (index >= argc){
                    printf("func crop: arguments are not enough\n");
                    break;
                }
                strtol(argv[index], &endptr, 10);
                if (endptr == argv[index] + strlen(argv[index])) {
                    crop.y2 = atoi(argv[index]);
                } else {
                    printf("func crop: the argument y2 should be type int\n");
                    break;
                }
                cropping(crop.x1, crop.y1, crop.x2, crop.y2, arr, &bmih, &bmfh, f);
                optind = index - 1;
                break;

            case 'h':
            case '?':
                printf("    BMP_PROCESSING PROGRAM    \n");
                printf("1) --line-l - arguments: x1 y1 x2 y2 thickness color\n");
                printf("COLOR LIST: [red, green, pink, orange, blue, purple, black, white, brown]\n");
                printf("2) --inv_1-i - arguments: x0 y0 radius\n");
                printf("3) --inv_2-I - arguments: x1 y1 x2 y2\n");
                printf("4) --crop-c - arguments: x1 y1 x2 y2\n");
                printf("5) --help-h - program manual\n");
                printf("6) --about_1-a - input file information\n");
                printf("7) --about_2-A - output file information\n");
                printf("8) --name_out-n - arguments: name output file\n");

                break;
        }
        opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    }





    //cropping(0, 0, 256, 256, arr, &bmih, &bmfh, f);

    printf("\n");
    free(arr);


    return 0;
}