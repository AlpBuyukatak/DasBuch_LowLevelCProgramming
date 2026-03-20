#include "data.h"

static int localCount = 0;

void accumulate(int x) {
    sum += x;
    counter++;
    localCount++;
}