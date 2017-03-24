#ifndef BMPWRITER_H 
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>


namespace BMPWriter {
    void write_bmp(
            std::string filename,
            std::vector<std::vector<std::vector<int> > > BMPImage
            );
}

#endif
