#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint32_t array[8];   // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
} pack_array;

void array2struct(int array[], pack_array *result)
{
    for (uint64_t i = 0; i < 32; i += 4)
    {
        uint8_t num_base16 = 0;
        uint8_t pow_2 = 1;
        for (uint8_t j = 4; j > 0; j--)
        {
            num_base16 += array[i + j - 1] * pow_2;
            pow_2 *= 2;
            if (array[i + j - 1] == 0)
            {
                result->count0++;
            }
            else
            {
                result->count1++;
            }
        }
        uint32_t c;
        if (num_base16 > 9)
        {
            c = 'a' + num_base16 - 10;
        }
        else
        {
            c = '0' + num_base16;
        }
        result->array[i / 4] = c;
    }
}

int main(void)
{
    pack_array test;
    int array[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1};
    array2struct(array, &test);
    printf("array: %ls\ncount0: %u\ncount1: %u\n", test.array, test.count0, test.count1);
    return 0;
}
