#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;                 

// We create 1KB of virtual memory and clean it up first
static BYTE mem[0x400] = {0};

//Base addresses in simulation: two arbitrary regions within the array
#define IN_BASE_OFF   0x100
#define OUT_BASE_OFF  0x200

#define INPORT_SIM    (mem + IN_BASE_OFF)
#define OUTPORT_SIM   (mem + OUT_BASE_OFF)

int main(void) {
    // A,B,C,D fields in INPORT (like A=0,B=1,C=2,D=3)
    INPORT_SIM[0] = 0xAA;   // A
    INPORT_SIM[2] = 0xB1;   // B  (ofset +2)
    INPORT_SIM[4] = 0xC2;   // C
    INPORT_SIM[6] = 0xD3;   // D

    // 2) Pointer Addressing with Offset  (in the simulation)
    BYTE *inport  = INPORT_SIM;
    BYTE *outport = OUTPORT_SIM;
    *(outport + 6) = *(inport + 2);   // D = B

    // 3) Absolute Addressing as an Array
    OUTPORT_SIM[6] = INPORT_SIM[2];

    // 1) Absolute Addressing of Memory Locations
    // We calculate index (base+offset) instead of "absolute address"??????im confused 
    mem[OUT_BASE_OFF + 6] = mem[IN_BASE_OFF + 2];  // *((BYTE*)0x1C8206) = *((BYTE*)0x1C8102);

    printf("IN.B  (IN[2])  = 0x%02X\n", INPORT_SIM[2]);
    printf("OUT.D (OUT[6]) = 0x%02X\n", OUTPORT_SIM[6]);  

    return 0;
}