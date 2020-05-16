#include "drawLine.h"
#include "validCoorFirst.h"
#include <stdlib.h>
#include <string.h>
#include "angle.h"
#include "BitmapInfoHeader.h"
#include "stdio.h"

void drawLine(int x1, int y1, int x2, int y2, Rgb **arr, char* color, int
thickness, BitmapInfoHeader *bmih, BitmapFileHeader *bmfh, FILE *f, char* name_out){
    int deltaT = 1;
    y1 = (int)(bmih -> height - 1) - y1;
    y2 = (int)(bmih -> height - 1) - y2;
    int W = 0;
    if ((int)bmih -> width * sizeof(Rgb) % 4 != 0){
        W = ((int)bmih -> width * sizeof(Rgb) + (4 - ((int)bmih -> width * 3) % 4));
    } else {
        W = (int)bmih -> width * sizeof(Rgb);
    }
    for (int k = 0; k < bmih -> height; k++){
        arr[k] = calloc(W, 1);
        fread(arr[k],1, W, f);
    }
    const int x_1 = x1, x_2 = x2, y_1 = y1, y_2 = y2;
    if(angle(x1, y1, x2, y2, bmih) <= 135 && angle(x1, y1, x2, y2, bmih) >= 45){
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
                                 "purple", "black", "white", "brown", "yellow"};
            Rgb rgb_arr_color[] = {{0,   0,   255},
                                   {0,   128, 0},
                                   {203, 192, 255},
                                   {0,   165, 255},
                                   {255, 0,   0},
                                   {128, 0,   128},
                                   {0,   0,   0},
                                   {255, 255, 255},
                                   {42,  42,  165},
                                   {0, 255, 255}};

            int color_on = 0;
            for (int i = 0; i < 10; i++) {
                if (!strcmp(arr_color[i], color)) {
                    cur = rgb_arr_color[i];
                    color_on = 1;
                }
            }
            if (!color_on){
                printf("func line: this color is not in the color list!\n");
                for (int k = 0; k < bmih -> height; k++){
                    free(arr[k]);
                }
                fseek(f,54,SEEK_SET);
                return;
            }
            if(x2 < (int)bmih -> width && x2 >= 0 && y2 >= 0 && y2 < (int)bmih -> height){
                arr[y2][x2] = cur;
            }
            while (y1 != y2 || x1 != x2) {
                if(x1 < (int)bmih -> width && x1 >= 0 && y1 >= 0 && y1 < (int)bmih -> height){
                    arr[y1][x1] = cur;
                }
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

            }
            if (deltaT < 0){
                x1 = x_1 + deltaT;
                x2 = x_2 + deltaT;
                deltaT--;
            }
            deltaT = -deltaT;


        }
    }

    if((angle(x1, y1, x2, y2, bmih) >= 0 && angle(x1, y1, x2, y2, bmih) < 45) || angle(x1, y1, x2, y2, bmih) > 135){
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
                                 "purple", "black", "white", "brown", "yellow"};
            Rgb rgb_arr_color[] = {{0,   0,   255},
                                   {0,   128, 0},
                                   {203, 192, 255},
                                   {0,   165, 255},
                                   {255, 0,   0},
                                   {128, 0,   128},
                                   {0,   0,   0},
                                   {255, 255, 255},
                                   {42,  42,  165},
                                   {0, 255, 255}};

            int color_on = 0;
            for (int i = 0; i < 10; i++) {
                if (!strcmp(arr_color[i], color)) {
                    cur = rgb_arr_color[i];
                    color_on = 1;
                }
            }
            if (!color_on){
                printf("func line: this color is not in the color list!\n");
                for (int k = 0; k < bmih -> height; k++){
                    free(arr[k]);
                }
                fseek(f, 54, SEEK_SET);

                return;
            }
            if(x2 < (int)bmih -> width && x2 >= 0 && y2 >= 0 && y2 < (int)bmih -> height){
                arr[y2][x2] = cur;
            }
            while (y1 != y2 || x1 != x2) {
                if(x1 < (int)bmih -> width && x1 >= 0 && y1 >= 0 && y1 < (int)bmih -> height){
                    arr[y1][x1] = cur;
                }
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

                y1 = y_1 + deltaT;
                y2 = y_2 + deltaT;

            }
            if (deltaT < 0){
                y1 = y_1 + deltaT;
                y2 = y_2 + deltaT;
                deltaT--;
            }
            deltaT = -deltaT;


        }
    }
    FILE *out_file = fopen(name_out, "wb");
    fwrite(bmfh, 1, sizeof(BitmapFileHeader),out_file);
    fwrite(bmih, 1, sizeof(BitmapInfoHeader), out_file);
    for (int i = 0; i < bmih -> height; i++){
        fwrite(arr[i], 1,W, out_file);
    }
    fclose(f);
    for (int k = 0; k < bmih -> height; k++){
        free(arr[k]);
    }
    f = fopen(name_out, "rb");
    fread(bmfh,1,sizeof(BitmapFileHeader),f);
    fread(bmih, 1, sizeof(BitmapInfoHeader), f);
    fclose(out_file);



}

