#include "BitmapInfoHeader.h"
#include "Rgb.h"
#include "BitmapFileHeader.h"
#include <bits/types/FILE.h>

void cropping(int x1, int y1, int x2, int y2, Rgb **arr, BitmapInfoHeader* bmih, BitmapFileHeader* bmfh, FILE *f, char *name_out);
