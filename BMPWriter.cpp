#include "BMPWriter.h"


/**
 * Write a BMP image.
 *
 * @param std::string filename,
 * @param std::vector<std::vector<std::vector<int>>> BMPImage - RGB + pixeldata
 */
void BMPWriter::write_bmp(
    std::string filename,
    std::vector<std::vector<std::vector<int>>> BMPImage
) {
    int h = BMPImage.size();
    int w = BMPImage[0].size();

    FILE *f;
    unsigned char *img = NULL;
    int filesize = 54 + 3 * w * h;

    if(img) {
        free(img);
    }

    img = (unsigned char *) malloc(3 * w * h);
    memset(img, 0, 3 * w * h);

    int x = 0;
    int y = 0;
    int xx = 0;
    int yy = 0;

    for(int xx = 0; xx < BMPImage.size(); xx++) {
        for(int yy = 0; yy < BMPImage[xx].size(); yy++) {
            if (BMPImage.size() > xx) {
                if (BMPImage[xx].size() > yy) {
                    if (BMPImage[xx][yy].size() > 0) {
                        y=(h-1)-yy;
                        img[(xx+y*w)*3+2] = (unsigned char)(BMPImage[xx][yy][0]);
                        img[(xx+y*w)*3+1] = (unsigned char)(BMPImage[xx][yy][1]);
                        img[(xx+y*w)*3+0] = (unsigned char)(BMPImage[xx][yy][2]);
                    }
                }
            }
        }
    }

    f = fopen(filename.c_str(),std::string("wb").c_str());

    unsigned char bmpfileheader[14] = {
        'B', 'M',       // bfType
        0, 0, 0, 0,     // bfSize
        0, 0,           // bfReserved1
        0, 0,           // bfReserved2
        54, 0, 0, 0     // bfOffBits
    };
    unsigned char bmpimageheader[40] = {
        40, 0, 0, 0,    // biSize
        0, 0, 0, 0,     // biWidth
        0, 0, 0, 0,     // biHeight
        1, 0,           // biPlanes
        24, 0           // biBitCount
    };
    unsigned char padding[3] = {0,0,0};

    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);

    bmpimageheader[4] = (unsigned char)(w);
    bmpimageheader[5] = (unsigned char)(w >> 8);
    bmpimageheader[6] = (unsigned char)(w >> 16);
    bmpimageheader[7] = (unsigned char)(w >> 24);
    bmpimageheader[8] = (unsigned char)(h);
    bmpimageheader[9] = (unsigned char)(h >> 8);
    bmpimageheader[10] = (unsigned char)(h >> 16);
    bmpimageheader[11] = (unsigned char)(h >> 24);

    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpimageheader, 1, 40, f);

    for(int i = 0; i < h; i++) {
        fwrite(img+(w*(h-i-1) * 3), 3, w, f);
        fwrite(padding, 1, ( 4 - (w * 3) % 4) % 4, f);
    }

    fclose(f);
}
