#include "drawCircle.h"
#include "string.h"
#include "validCoorSecond.h"
#include "drawLine.h"

void drawCircle(int x0, int y0, int radius, Rgb **arr, BitmapInfoHeader *bmih, char *color){
    int radius_counter = radius;
    validCoorSecond(&x0, &y0, bmih);
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
    int y = 0;
    int x = radius;
    int delta = 1 - 2 * radius;
    int error = 0;
    while (x >= 0) {
        //setPixel(x0 + x, y0 + y);
        if ((y0 + y) < bmih->height && (y0 + y) >= 0 && (x0 + x) < bmih->width && (x0 + x) >= 0) {
            arr[y0 + y][x0 + x] = cur;
        }
        //setPixel(x0 + x, y0 - y);
        if ((y0 + y) < bmih->height && (y0 + y) >= 0 && (x0 - x) < bmih->width && (x0 - x) >= 0) {
            arr[y0 + y][x0 - x] = cur;
        }
        //setPixel(x0 - x, y0 + y);
        if ((y0 - y) < bmih->height && (y0 - y) >= 0 && (x0 + x) < bmih->width && (x0 + x) >= 0) {
            arr[y0 - y][x0 + x] = cur;
        }
        //setPixel(x0 - x, y0 - y);
        if ((y0 - y) < bmih->height && (y0 - y) >= 0 && (x0 - x) < bmih->width && (x0 - x) >= 0) {
            arr[y0 - y][x0 - x] = cur;
        }
        //drawLine(x0 - x, y0 - y, x0 - x, y0 + y, arr, bmih, color, 1);

        error = 2 * (delta + x) - 1;
        if (delta < 0 && error <= 0) {
            ++y;
            delta += 2 * y + 1;
            continue;
        }
        error = 2 * (delta - y) - 1;
        if (delta > 0 && error > 0) {
            --x;
            delta += 1 - 2 * x;
            continue;
        }
        ++y;
        delta += 2 * (y - x);
        --x;
    }


}


