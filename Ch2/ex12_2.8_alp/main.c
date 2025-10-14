//the code has taken from: https://www.geeksforgeeks.org/c/c-pointers/
//addressing type normal level
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void) {
    uint8_t memory[4] = { 0x11, 0x22, 0x33, 0x44 };

    // Bayt bayt okuma
    for (int i = 0; i < 4; ++i)
        printf("pChar[%d] = 0x%02X\n", i, memory[i]);

    // 4 baytı tek bir 32-bit değere kopyala (hizalama/aliasing sorunu yok)
    uint32_t val = 0;
    memcpy(&val, memory, 4);
    printf("val (raw) = 0x%08X\n", val);

    // Endianness’a göre anlamlı gösterim
    uint32_t little = (uint32_t)memory[0]
                    | ((uint32_t)memory[1] << 8)
                    | ((uint32_t)memory[2] << 16)
                    | ((uint32_t)memory[3] << 24);
    uint32_t big    = (uint32_t)memory[3]
                    | ((uint32_t)memory[2] << 8)
                    | ((uint32_t)memory[1] << 16)
                    | ((uint32_t)memory[0] << 24);

    printf("as little-endian = 0x%08X\n", little); // tipik PC: 0x44332211
    printf("as big-endian    = 0x%08X\n", big);    // big-endian: 0x11223344
    return 0;
}