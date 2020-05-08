#include "inversion1.h"
#include "validCoorSecond.h"
#include "drawLine.h"

void inversion1(int x0, int y0, int radius, Rgb **arr, BitmapInfoHeader *bmih){
    validCoorSecond(&x0, &y0, bmih);
    int dx = 0;
    int dy = 0;
    int square_coord_x = x0 - radius;
    int square_coord_y = y0 - radius;
    for (int i = 0; i < 2 * radius; i++){
        for (int j = 0; j < 2 * radius; j++){
            dx = x0 - square_coord_x;
            dy = y0 - square_coord_y;
            if ((dx * dx + dy * dy) < (radius * radius) && (square_coord_x < (int)bmih -> width && square_coord_x >= 0 && square_coord_y >= 0 && square_coord_y < (int)bmih -> height)){
                arr[square_coord_y][square_coord_x].r = ~arr[square_coord_y][square_coord_x].r;
                arr[square_coord_y][square_coord_x].g = ~arr[square_coord_y][square_coord_x].g;
                arr[square_coord_y][square_coord_x].b = ~arr[square_coord_y][square_coord_x].b;
            }

            square_coord_y++;
        }
        square_coord_y = y0 - radius;
        square_coord_x++;
    }


}


