#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * Программа, необходимая для подсчета символов, строк и слов в необходимом файле
 * @param argc
 * @param argv
 * @return
 */

int solve(int argc, char *argv[]){
    FILE *file;
    char currentChar, previousChar;

    int countOfSymbol = 0;
    int countOfWords = 0;
    int countOfLines = 0;

    file = fopen(argv[argc - 1], "r");

    if (file == NULL) {
        fprintf(stderr, "Не получилось открыть файл %s \n", argv[argc - 1]);
        return -1;
    }

    while ((currentChar = fgetc(file)) != EOF) {

        if (currentChar == '\n') {
            countOfLines++;
        } else {
            if (previousChar == '\0' || isspace(previousChar)) {
                countOfWords += 1;
            }
        }

        countOfSymbol++;
        previousChar = currentChar;
    }

    for (int i = 0; i < argc; ++i) {

        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--bytes") == 0) {
            printf("Файл весит: %d\n", countOfSymbol);
        }

        if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--words") == 0) {
            printf("Количество слов: %d\n", countOfWords);
        }

        if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0) {
            printf("Количество строк: %d\n", countOfLines + 1);
        }
    }

    fclose(file);

    return 0;
}

int main() {
    solve(4, "-c" "-l" "-w" "test.txt");
}