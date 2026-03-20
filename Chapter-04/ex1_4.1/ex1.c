//4.1 Pointer to an Array
/*
This code simulates copying a byte from an input port to an output port using three different 
methods—absolute addressing, pointer arithmetic, and array indexing to show that 
all approaches access the same memory location and produce the same result.
*/
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;   // BYTE = unsigned char (1 byte)

int main(void) {
    // Simulated input and output ports (arrays)
    BYTE INPORT[8]  = {'A', 'B', 'C', 'D', 0, 0, 0, 0};
    BYTE OUTPORT[8] = {0};

    // 1️.Absolute Addressing (simulated)
    // Imagine these are fixed hardware addresses:
    // *((BYTE*)0x1C8206) = *((BYTE*)0x1C8102);
    OUTPORT[6] = INPORT[2];

    // 2️.Pointer Addressing with Offset
    BYTE *inport  = INPORT;
    BYTE *outport = OUTPORT;
    *(outport + 6) = *(inport + 2);

    // 3️.Array Indexing (most readable form)
    #define INPORT_PTR  (INPORT)
    #define OUTPORT_PTR (OUTPORT)
    OUTPORT_PTR[6] = INPORT_PTR[2];

    // Display results
    printf("INPORT[2]  = %c\n", INPORT[2]);
    printf("OUTPORT[6] = %c\n", OUTPORT[6]);

    return 0;
}
