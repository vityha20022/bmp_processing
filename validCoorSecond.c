#include "validCoorSecond.h"

void validCoorSecond(int *x0, int *y0, BitmapInfoHeader *bmih){
    if (*y0 > (int)(bmih -> height - 1)) {
        *y0 = 0;
    } else{
        if (*y0 < 0) {
            *y0 = (int)(bmih -> height - 1);
        } else{
            *y0 = (int)(bmih -> height - 1) - *y0;
        }
    }

    if (*x0 > (int)(bmih -> width - 1)) {
        *x0 = (int)(bmih -> width - 1);
    }
    if (*x0 < 0) {
        *x0 = 0;
    }
}