//1.2.1 Data Type double
/*
//this code has just prepared for a comparising between writing speeds
float → less memory, preferred if sufficient accuracy is required.
double → more memory but more precision.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef N
#define N (50*1000*1000)   // 50M eleman (lower it if you dont have enough memory)
#endif

int main(void) {
    // float row: 50M * 4 byte = ~200 MB
    float  *af = (float*)  malloc(N * sizeof(float));
    float  *bf = (float*)  malloc(N * sizeof(float));
    // double row: 50M * 8 byte = ~400 MB
    double *ad = (double*) malloc(N * sizeof(double));
    double *bd = (double*) malloc(N * sizeof(double));

    if (!af || !bf || !ad || !bd) { puts("alloc fail"); return 1; }

    for (int i = 0; i < N; ++i) {
        af[i] = (float)(i % 100) * 0.1f;
        bf[i] = (float)((i % 37) - 18) * 0.2f;
        ad[i] = (double)(i % 100) * 0.1;
        bd[i] = (double)((i % 37) - 18) * 0.2;
    }

    clock_t t0, t1; double sum;

    // float MAC
    t0 = clock();
    sum = 0.0;
    for (int i = 0; i < N; ++i) sum += (double)(af[i] * bf[i]);
    t1 = clock();
    double float_sec = (double)(t1 - t0) / CLOCKS_PER_SEC;

    // double MAC
    t0 = clock();
    double sum2 = 0.0;
    for (int i = 0; i < N; ++i) sum2 += ad[i] * bd[i];
    t1 = clock();
    double double_sec = (double)(t1 - t0) / CLOCKS_PER_SEC;

    printf("float  time: %.3f s (sum=%f)\n", float_sec, sum);
    printf("double time: %.3f s (sum=%f)\n", double_sec, sum2);

    free(af); free(bf); free(ad); free(bd);
    return 0;
}