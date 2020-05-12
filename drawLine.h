#include <bits/types/FILE.h>
#include "Rgb.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

void drawLine(int x1, int y1, int x2, int y2, Rgb **arr, char* color, int
thickness, BitmapInfoHeader *bmih, BitmapFileHeader *bmfh, FILE* f);