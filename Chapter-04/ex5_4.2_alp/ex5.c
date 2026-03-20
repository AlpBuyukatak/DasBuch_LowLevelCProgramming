//4.2 Array Address as a Function Argument
// copy_benchmark_portable.c it just compares the indexing and pointer speed. BENCHMARK TEST
/*
This program benchmarks and compares the speed of two array copy methods—one using 
indexing (dst[i] = src[i]) and one using pointer arithmetic (*dst++ = *src++)—by timing 
them over a large number of elements and reporting their performance in GB/s. 
It also does a small correctness check to ensure both methods produce the same result.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#ifndef REPEATS
#define REPEATS 5        // number of measurements (after a warm-up)
#endif

typedef uint32_t WORD;    // 4-byte element helps saturate memory bandwidth

/* 1) Indexing copy */
static void copy_index(WORD *dst, const WORD *src, size_t n) {
    for (size_t i = 0; i < n; ++i) dst[i] = src[i];
}

/* 2) Pointer copy */
static void copy_ptr(WORD *dst, const WORD *src, size_t n) {
    while (n--) *dst++ = *src++;
}

static double run_once(void (*fn)(WORD*, const WORD*, size_t),
                       WORD *dst, const WORD *src, size_t n)
{
    clock_t t0 = clock();
    fn(dst, src, n);
    clock_t t1 = clock();
    // prevent over-optimization
    volatile WORD sink = dst[n/2]; (void)sink;
    return (double)(t1 - t0) / CLOCKS_PER_SEC;
}

static void bench(const char *name,
                  void (*fn)(WORD*, const WORD*, size_t),
                  WORD *dst, const WORD *src, size_t n)
{
    // warm-up
    run_once(fn, dst, src, n);

    double best = 1e9, sum = 0.0;
    for (int r = 0; r < REPEATS; ++r) {
        double dt = run_once(fn, dst, src, n);
        if (dt < best) best = dt;
        sum += dt;
    }
    double avg = sum / REPEATS;

    // report (GB/s)
    double bytes = (double)n * sizeof(WORD);
    double gbs_best = (bytes / best) / 1e9;
    double gbs_avg  = (bytes / avg)  / 1e9;

    printf("%s: best %.6f s (%.2f GB/s), avg %.6f s (%.2f GB/s)\n",
           name, best, gbs_best, avg, gbs_avg);
}

int main(int argc, char **argv) {
    // default: 50M elements -> ~200 MB per array (check your RAM!)
    size_t n = (argc > 1) ? (size_t)strtoull(argv[1], NULL, 10) : 50000000ULL;

    printf("Element size: %zu bytes (WORD)\n", sizeof(WORD));
    printf("Elements: %llu  (~%.1f MB per array)\n",
           (unsigned long long)n,
           (double)n * sizeof(WORD) / (1024.0 * 1024.0));

    WORD *src = (WORD*)malloc(n * sizeof(WORD));
    WORD *dst1 = (WORD*)malloc(n * sizeof(WORD));
    WORD *dst2 = (WORD*)malloc(n * sizeof(WORD));
    if (!src || !dst1 || !dst2) {
        fprintf(stderr, "Allocation failed. Try smaller N (e.g., 20000000).\n");
        free(src); free(dst1); free(dst2);
        return 1;
    }

    for (size_t i = 0; i < n; ++i) src[i] = (WORD)i;

    bench("Indexing  (dst[i] = src[i])", copy_index, dst1, src, n);
    bench("Pointer   (*d++ = *s++)   ", copy_ptr,  dst2, src, n);

    // quick correctness check
    printf("Check: dst1[123456] = %u, dst2[123456] = %u\n",
           (unsigned)dst1[(n>123456)?123456:0],
           (unsigned)dst2[(n>123456)?123456:0]);

    free(src); free(dst1); free(dst2);
    return 0;
}
