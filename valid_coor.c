#include "valid_coor.h"
#include "BitmapInfoHeader.h"
void valid(int *x1, int *y1, int *x2, int *y2, BitmapInfoHeader *bmih){
    if (*y1 > (int)(bmih -> height - 1)) {
        *y1 = 0;
    }

    if (*y1 < 0) {
        *y1 = (int)(bmih -> height - 1);
    }
    if (*y2 > (int)(bmih -> height - 1)) {
        *y2 = 0;
    }
    if (*y2 < 0) {
        *y2 = (int)(bmih -> height - 1);
    }

    if (*x1 > (int)(bmih -> width - 1)) {
        *x1 = (int)(bmih -> width - 1);
    }
    if (*x1 < 0) {
        *x1 = 0;
    }
    if (*x2 > (int)(bmih -> width - 1)) {
        *x2 = (int)(bmih -> width - 1);
    }
    if (*x2 < 0) {
        *x2 = 0;
    }


}
