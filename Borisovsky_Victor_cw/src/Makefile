all: bmp_processing


bmp_processing: main.o drawLine.o inversion1.o inversion2.o cropping.o angle.o PrintHelp.o validCoorFirst.o
	gcc main.o drawLine.o inversion1.o inversion2.o cropping.o angle.o PrintHelp.o validCoorFirst.o -lm -o bmp_proc

main.o: main.c BitmapInfoHeader.h BitmapFileHeader.h Rgb.h validCoorFirst.h angle.h drawLine.h inversion1.h inversion2.h cropping.h PrintHelp.h
	gcc -c main.c

drawLine.o: drawLine.c drawLine.h angle.h BitmapInfoHeader.h 
	gcc -c drawLine.c

inversion1.o: inversion1.c inversion1.h
	gcc -c inversion1.c

inversion2.o: inversion2.c inversion2.h
	gcc -c inversion2.c

cropping.o: cropping.c cropping.h validCoorFirst.h
	gcc -c cropping.c

PrintHelp.o: PrintHelp.c PrintHelp.h
	gcc -c PrintHelp.c

angle.o: angle.c angle.h 
	gcc -c angle.c

validCoorFirst.o: validCoorFirst.c validCoorFirst.h
	gcc -c validCoorFirst.c


clean:
	rm *.o

