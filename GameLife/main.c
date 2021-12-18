#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *itoa(int value, char *result, int base) {
    if (base < 2 || base > 36) {
        *result = '\0';
        return result;
    }
    char *ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
    } while (value);

    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

void GameLife(int **life, int height, int width) {
    int neighbors;
    int tmp[height][width];
    int x, y;
    int inf = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            tmp[y][x] = life[y][x];
        }
    }
    for (y = 1; y < height - 1; y++) {
        for (x = 1; x < width - 1; x++) {
            neighbors = life[y + 1][x - 1] + life[y + 1][x] + life[y + 1][x + 1] + life[y][x - 1] + life[y][x + 1] +
                        life[y - 1][x - 1] + life[y - 1][x] + life[y - 1][x + 1];
            if (tmp[y][x] == 1) {
                if (neighbors == 2) {
                    tmp[y][x] = life[y][x];
                }
                if (neighbors == 3) {
                    tmp[y][x] = life[y][x];
                }
                if (neighbors > 3) {
                    tmp[y][x] = 0;
                }
                if (neighbors < 2) {
                    tmp[y][x] = 0;
                }
            } else {
                if (neighbors == 3) {
                    tmp[y][x] = 1;
                }
            }
            neighbors = 0;
        }
    }
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (life[y][x] == tmp[y][x]) {
                inf++;
            }
            life[y][x] = tmp[y][x];
        }
    }
    if (inf == height * width) {
        exit(0);
    }
}

struct Bmp {
    int Width;
    int Height;
    int Size;
};

int main(int argc, char *argv[]) {
    struct Bmp Image;
    unsigned char header[54];
    int i, j, k, l, m;
    int maxiter, dumpfreq = 1;
    char *dirname;
    FILE *file;

    for (i = 0; i < argc; i++) {
        if (!strcmp("--input", argv[i])) {
            file = fopen(argv[1 + 1], "rb");
        }
        if (!strcmp("--output", argv[i])) {
            dirname = argv[i + 1];
            mkdir(dirname, 0700);
        }
        if (!strcmp("--max_iter", argv[i])) {
            maxiter = strtol(argv[i + 1], 0, 10);
        }
        if (!strcmp("--dump_freq", argv[i])) {
            dumpfreq = strtol(argv[i + 1], 0, 10);
        }
    }

    //READ IMAGE SIZE, HEIGHT, WIDTH, BYTE
    fread(header, 1, 54, file);
    Image.Width = header[21] * 256 * 256 * 256 + header[20] * 256 * 256 + header[19] * 256 + header[18];
    Image.Height = header[25] * 256 * 256 * 256 + header[24] * 256 * 256 + header[23] * 256 + header[22];
    Image.Size = header[5] * 256 * 256 * 256 + header[4] * 256 * 256 + header[3] * 256 + header[2];
    unsigned char imagebyte[Image.Size - 54];
    fread(imagebyte, 1, Image.Size, file);

    int **img = (int **) malloc(Image.Height * sizeof(int *));
    for (i = 0; i < Image.Height; i++)
        img[i] = (int *) malloc(Image.Width * sizeof(int));

    //MAKE TO ONE-ZERO ARRAY
    k = -(Image.Width % 4);
    for (i = Image.Height - 1; i >= 0; i--) {
        k += (Image.Width % 4);
        for (j = 0; j < Image.Width; j++) {
            if (imagebyte[k] == 255)
                img[i][j] = 0;
            else
                img[i][j] = 1;
            k += 3;
        }
    }

    for (l = 1; l <= maxiter; l++) {
        if (l % dumpfreq == 0) {
            char filename[l];
            char way[20];
            strcpy(way, dirname);
            strcat(strcat(way, "\\"), strcat(itoa(l, filename, 10), ".bmp"));
            FILE *life = fopen(way, "w");
            fwrite(header, 1, 54, life);
            m = 0;
            // MAKE BITMAP
            for (i = Image.Height - 1; i >= 0; i--) {
                for (j = 0; j < Image.Width; j++) {
                    for (k = 0; k < 3; k++) {
                        if (img[i][j] == 1)
                            imagebyte[m] = 0;
                        else
                            imagebyte[m] = 255;
                        m++;
                    }
                }
                while (m % 4 != 0) {
                    imagebyte[m] = 0;
                    m++;
                }
            }
            fwrite(imagebyte, 1, Image.Size, life);
            fclose(life);
        }
        //GAME
        GameLife(img, Image.Height, Image.Width);
    }
    free(img);
    return 0;
}