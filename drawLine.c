#include "drawLine.h"
#include "valid_coor.h"
#include <stdlib.h>
#include <string.h>
#include "angle.h"

void drawLine(int x1, int y1, int x2, int y2, Rgb **arr, char* color, int
thickness){
    int deltaT = 1, deltaX1 = 1, deltaY1 = 1, deltaX2 = 1, deltaY2 = 1;
    valid(&x1, &y1, &x2, &y2);
    const int x_1 = x1, x_2 = x2, y_1 = y1, y_2 = y2;
    //first angle
    if (angle(x1, y1, x2, y2) <= 90 && angle(x1, y1, x2, y2) >= 45){
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
                if (x2 > 779){
                    y2 = y_2 - deltaY2;
                    if (y2 < y_1){
                        y2 = y_1;
                    }
                    deltaY2++;
                }


            }
            if (deltaT < 0){
                x1 = x_1 + deltaT;
                x2 = x_2 + deltaT;
                if (x1 < 0 && y1 != y_2){
                    y1 = y_1 + deltaY1;
                    if (y1 > y_2){
                        y1 = y_2;
                    }
                    deltaY1++;
                }
                deltaT--;
            }
            valid(&x1, &y1, &x2, &y2);
            deltaT = -deltaT;
        }
    }
    //first angle
    if (angle(x1, y1, x2, y2) <  45 && angle(x1, y1, x2, y2) >= 0){
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

                y1 = y_1 + deltaT;
                y2 = y_2 + deltaT;
                if (y2 > 562){
                    x2 = x_2 - deltaX2;
                    if (x2 < x_1){
                        x2 = x_1;
                    }
                    deltaX2++;
                }


            }
            if (deltaT < 0){
                y1 = y_1 + deltaT;
                y2 = y_2 + deltaT;
                if (y1 < 0 && x1 != x_2){
                    x1 = x_1 + deltaX1;
                    if (x1 > x_2){
                        x1 = x_2;
                    }
                    deltaX1++;
                }
                deltaT--;
            }
            valid(&x1, &y1, &x2, &y2);
            deltaT = -deltaT;
        }
    }

}

