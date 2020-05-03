#include "valid_coor.h"
void valid(int *x1, int *y1, int *x2, int *y2){
    if (*y1 > 562) {
        *y1 = 562;
    }

    if (*y1 < 0) {
        *y1 = 0;
    }
    if (*y2 > 562) {
        *y2 = 562;
    }
    if (*y2 < 0) {
        *y2 = 0;
    }

    if (*x1 > 779) {
        *x1 = 779;
    }
    if (*x1 < 0) {
        *x1 = 0;
    }
    if (*x2 > 779) {
        *x2 = 779;
    }
    if (*x2 < 0) {
        *x2 = 0;
    }

}
