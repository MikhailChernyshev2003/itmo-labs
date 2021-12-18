#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct uint1024_t {
    uint64_t parts[16];
} uint1024_t;

uint1024_t from_uint(uint64_t x) {
    uint1024_t result;

    for (int i = 0; i < 16; i++) {
        if (i == 0) {
            result.parts[i] = x;
        } else {
            result.parts[i] = 0;
        }
    }
    return result;
};

uint1024_t add_op(uint1024_t x, uint1024_t y) {
    int overflow = 0;
    uint64_t sum;
    uint1024_t result = from_uint(0);

    for (int i = 0; i < 16; i++) {
        sum = x.parts[i] + y.parts[i] + overflow;
        result.parts[i] = sum;

        if (sum < x.parts[i] || sum < y.parts[i]) {
            overflow = 1;
        } else {
            overflow = 0;
        }

    }

    return result;
};

uint1024_t subtr_op(uint1024_t x, uint1024_t y) {
    for (int i = 0; i < 16; i++) {
        y.parts[i] ^= 18446744073709551615; // 18446744073709551615 - максимальное uint64_t число
    }

    uint1024_t result = add_op(x, add_op(y, from_uint(1)));
    return result;
};

bool isZero(uint1024_t x) {

    for (int i = 0; i < 16; i++) {
        if (x.parts[i] != 0) {
            return false;
        }
    }

    return true;
}

uint1024_t mult_op(uint1024_t x, uint1024_t y) {
    uint1024_t result = from_uint(0);

    while (!isZero(x)) {
        result = add_op(result, y);
        x = subtr_op(x, from_uint(1));
    }

    return result;
};

void printf_value(uint1024_t x) {
    unsigned char result[155];

    memset(result, 0, sizeof(result));

    for (int i = 16 - 1; i >= 0; i--) {
        for (int j = 64 - 1; j >= 0; j--) {
            int new_bit = (x.parts[i] >> j) & 1;
            int carry_bit, prev_carry_bit = 0;

            for (int k = 155 - 1; k >= 0; k--) {
                carry_bit = (result[k] >> 7) & 1;
                result[k] <<= 1;
                if (k == 154) {
                    result[k] += new_bit;
                } else {
                    result[k] += prev_carry_bit;
                }

                if (j == 0) {
                    prev_carry_bit = carry_bit;
                    continue;
                }

                int rightPart = result[k] & 15;

                if (rightPart >= 5) {
                    if (result[k] + 3 < result[k]) {
                        carry_bit += 1;
                    }
                    result[k] += 3;
                }

                int leftPart = (result[k] >> 4) & 15;

                if (leftPart >= 5) {
                    if (result[k] + 48 < result[k]) {
                        carry_bit += 1;
                    }
                    result[k] += 48;
                }

                prev_carry_bit = carry_bit;
            }
        }
    }

    bool resulting = true;

    for (int i = 0; i < 155; i++) {
        int leftPart = ((1 << 4) - 1) & result[i];
        int rightPart = ((1 << 4) - 1) & (result[i] >> 4);

        if (rightPart != 0 || !resulting) {
            printf("%d", rightPart);
            resulting = false;
        }

        if (leftPart != 0 || !resulting) {
            printf("%d", leftPart);
            resulting = false;
        }
    }
    if (resulting) {
        printf("0");
    }
    printf("\n");
}

void scanf_value(uint1024_t *x) {
    for (int i = 0; i < 16; i++) {
        x->parts[i] = 0;
    }

    char c;

    while (true) {
        c = getchar();
        if (c == '\n') {
            break;
        } else if (c >= '0' && c <= '9') {
            *x = mult_op(*x, from_uint(10));
            *x = add_op(*x, from_uint(c - '0'));
        }
    }

}

int main() {
    uint1024_t firstNumber, secondNumber;

    printf("Введите первое число: ");
    scanf_value(&firstNumber);

    printf("Введите второе число: ");
    scanf_value(&secondNumber);

    printf("Сумма этих чисел: ");
    printf_value(add_op(firstNumber, secondNumber));

    printf("Разность этих чисел: ");
    printf_value(subtr_op(firstNumber, secondNumber));

    printf("Введите первое число: ");
    scanf_value(&firstNumber);

    printf("Введите второе число: ");
    scanf_value(&secondNumber);

    printf("Произведение этих чисел: ");
    printf_value(mult_op(firstNumber, secondNumber));

    return 0;
}