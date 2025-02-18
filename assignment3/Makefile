CC = g++
CFLAGS = -g -Wall

LIBPNG = ../libpng-1.6.45  
INCLUDE = -I$(LIBPNG) 
LIBRARY_PATH = -L$(LIBPNG)
LIBS = -lpng 

OBJS = fernPNG.o pngWriter.o point.o transform.o

fernPNG: $(OBJS)
	$(CC) $(CFLAGS) $(LIBRARY_PATH) -o fernPNG $(OBJS) $(LIBS)

fernPNG.o: fernPNG.cpp pngWriter.h transform.h point.h
	$(CC) $(CFLAGS) $(INCLUDE) -c fernPNG.cpp -o fernPNG.o

pngWriter.o: pngWriter.cpp pngWriter.h
	$(CC) $(CFLAGS) $(INCLUDE) -c pngWriter.cpp -o pngWriter.o

point.o: point.cpp point.h
	$(CC) $(CFLAGS) $(INCLUDE) -c point.cpp -o point.o

transform.o: transform.cpp transform.h
	$(CC) $(CFLAGS) $(INCLUDE) -c transform.cpp -o transform.o

clean:
	rm -f $(OBJS) fernPNG
