#include <bits/types/FILE.h>
#include "BitmapInfoHeader.h"
#include "Rgb.h"
#include "BitmapFileHeader.h"

void inversion1(int x0, int y0, int radius, Rgb **arr, BitmapInfoHeader *bmih, BitmapFileHeader *bmfh, FILE *f, char *name_out);