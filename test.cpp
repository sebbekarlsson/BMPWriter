#include "BMPWriter.h" 
#include <random>


int main (int args, char ** argv) {
    srand(time(NULL));

    std::vector<std::vector<std::vector<int> > > BMPImage;

    int w = 512;
    int h = 512;

    BMPImage.resize(w);
    
    for (int x = 0; x < w; x++) {
        BMPImage[x].resize(h-1);
        BMPImage[x].push_back(std::vector<int>());
        for (int y = 0; y < h; y++) {
            BMPImage[x][y].push_back(rand()%(255-0 + 1) + 255);
            BMPImage[x][y].push_back(rand()%(255-0 + 1) + 255);
            BMPImage[x][y].push_back(rand()%(255-0 + 1) + 255);
        }
    }
    
    BMPWriter::write_bmp("test.bmp", BMPImage);
}
