CC = gcc -std=c11
CFLAGS = -g -Wall -ansi -pedantic
CLINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

key_engine.o: key_engine.h
	$(CC) $(CFLAGS) key_engine.c -c $(SLINKER_FLAGS);

time_engine.o: time_engine.h
	$(CC) $(CFLAGS) time_engine.c -c

draw_engine.o: draw_engine.h
	$(CC) $(CFLAGS) draw_engine.c -c $(SLINKER_FLAGS)
	
color_engine.o: color_engine.h
	$(CC) $(CGLAGS) color_engine.c -c

file_engine.o: file_engine.h
	$(CC) $(CFLAGS) file_engine.c -c

digit_engine.o: digit_engine.h
	$(CC) $(CFLAGS) digit_engine.c -c 

sdl_engine.o: sdl_engine.h
	$(CC) $(CFLAGS) sdl_engine.c -c $(CLINKER_FLAGS)

watch:      key_engine.o time_engine.o draw_engine.o color_engine.o file_engine.o digit_engine.o sdl_engine.o  main.c
	$(CC) $(CFLAGS)  key_engine.o time_engine.o draw_engine.o color_engine.o file_engine.o digit_engine.o sdl_engine.o main.c -o watch $(CLINKER_FLAGS)



clean:
	rm -rf *.o


