#include "validCoorFirst.h"
#include "BitmapInfoHeader.h"
void validCoorFirst(int *x1, int *y1, int *x2, int *y2, BitmapInfoHeader *bmih){
    if (*y1 > (int)(bmih -> height)) {
        *y1 = 0;
    } else{
        if (*y1 < 0) {
            *y1 = (int)(bmih -> height);
        } else{
            *y1 = (int)(bmih -> height) - *y1;
        }
    }

    if (*y2 > (int)(bmih -> height)) {
        *y2 = 0;
    } else{
        if (*y2 < 0) {
            *y2 = (int)(bmih -> height);
        } else{
            *y2 = (int)(bmih -> height) - *y2;
        }
    }


    if (*x1 > (int)(bmih -> width)) {
        *x1 = (int)(bmih -> width);
    }
    if (*x1 < 0) {
        *x1 = 0;
    }
    if (*x2 > (int)(bmih -> width)) {
        *x2 = (int)(bmih -> width);
    }
    if (*x2 < 0) {
        *x2 = 0;
    }



}
