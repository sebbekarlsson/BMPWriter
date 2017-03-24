# BMPWriter
> Write BMP files in C++, turn RGB data to BMP files.


## Install
> To compile and install to your system run:

        sudo make install

## Using the library
> To use the library in your project, simply add this flag in your compile
> script:

        -lbmpwriter

> Make sure you have installed it first.

### Function

        write_bmp(filename, rgbvector)

> The first argument is a filename, and the second argument is a vector
> that looks like this: std::vector\<std::vector\<std::vector\<int\>\>\>.

        [
            [
                [r, g, b], [r, g, b], [r, g, b]
            ],
            [
                [r, g, b], [r, g, b], [r, g, b]
            ],
            [
                [r, g, b], [r, g, b], [r, g, b]
            ],
            [
                [r, g, b], [r, g, b], [r, g, b]
            ],
            [
                [r, g, b], [r, g, b], [r, g, b]
            ],
            [
                [r, g, b], [r, g, b], [r, g, b]
            ]
        ]

> This is a psuedo-example of the vector, this would produce a BMP with the
> `width` of `3` and the `height` of `6`.

> You should be able to find a real example in `test.cpp`.

## Developing
> To develop, compile and run the "test" program, run:

        make
        make test
        ./test.a
