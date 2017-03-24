OS := $(shell uname)

$(info $(OS))

ifeq ($(OS), Darwin)
    FLAGZ=std=c++11 -g
else
    FLAGZ=std=c++11 -g
endif

G_FLAGZ=-std=c++11

$(info $(FLAGZ))

OFILES=\
       BMPWriter.o

OFILES_TEST=\
	    BMPWriter.o

LIBFILES=libbmpwriter.a libbmpwriter.so


all: $(OFILES) $(LIBFILES)	

BMPWriter.o: BMPWriter.cpp BMPWriter.h
	g++ $(G_FLAGZ) -c BMPWriter.cpp

libbmpwriter.a: $(OFILES)
	ar rcs $@ $^

libbmpwriter.so: $(OFILES)
	ar rcs $@ $^

install:
	-rm /usr/local/lib/libbmpwriter.*
	-rm -rf /usr/local/include/bmpwriter
	make
	mkdir -p bmpwriter
	cp *.h bmpwriter/.
	mv bmpwriter /usr/local/include/bmpwriter
	mv libbmpwriter.a /usr/local/lib/libbmpwriter.a
	mv libbmpwriter.so /usr/local/lib/libbmpwriter.so

test:
	g++ test.cpp -o test.a $(OFILES_TEST)

clean:
	-rm -rf bmpwriter
	-rm *.o
	-rm *.out
	-rm *.so
	-rm *.a
	-rm *.bmp
