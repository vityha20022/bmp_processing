#include "PrintHelp.h"
#include <stdio.h>

void PrintHelp(){
    printf("    BMP_PROCESSING PROGRAM    \n");
    printf("1) --line-l - arguments: x1 y1 x2 y2 thickness color\n");
    printf("COLOR LIST: [red, green, pink, orange, blue, purple, black, white, brown, yellow]\n");
    printf("2) --inv_1-i - arguments: x0 y0 radius\n");
    printf("3) --inv_2-I - arguments: x1 y1 x2 y2\n");
    printf("4) --crop-c - arguments: x1 y1 x2 y2\n");
    printf("5) --help-h - program manual\n");
    printf("6) --about-a - output file information\n");
    printf("7) --name_out-n - arguments: name output file\n");
}
