#ifndef BMPWRITER_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>


class BMPWriter {
    public:
        BMPWriter();

        void write_bmp(std::string filename, int w, int h, std::vector<std::vector<std::vector<int> > > BMPImage);
};

#endif
