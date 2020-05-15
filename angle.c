#include "angle.h"
#include "validCoorFirst.h"
#include "BitmapInfoHeader.h"
#include <math.h>
float angle(int x1, int y1, int x2, int y2, BitmapInfoHeader *bmih){
    validCoorFirst(&x1, &y1, &x2, &y2, bmih);
    float A = -(y1 - y2);
    float B = (x2 - x1);
    if (A == 0 && B == 0){
        return 0;
    }
    float k = (A/B);
    float angle = atan(k) * 180 / M_PI;
    if (angle < 0){
        angle += 180;
    }
    return angle;
}