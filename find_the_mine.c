#include <stdlib.h>

size_t *mine_location(size_t n, const int f[n][n]) {
  size_t* res=calloc(2, sizeof(size_t));;
  for(size_t i=0;i<n;++i){
    for(size_t j=0;j<n;++j){
      if(f[i][j]==1){
        res[0]=i;
        res[1]=j;
        break;
      }
    }
  }
  return res;
}

///////////////////////
#include <stdlib.h>

size_t *mine_location(size_t n, int field[n][n]) {
  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
      if (field[y][x] == 1)
      {
        size_t *r = malloc(2 * sizeof(size_t));
        r[0] = y;
        r[1] = x;
        return r;
      }
  return NULL;
}
///////////////////
#include <stdlib.h>

size_t *mine_location(size_t n, int field[n][n])
{
  size_t *r = malloc(2 * sizeof(size_t));
  for (int *p = field, i = 0; i < n * n; i++)
    if (*p++) return r[0] = i / n, r[1] = i % n, r;
}

//////////////////
#include <stdlib.h>
#ifdef __AVX2__
#include <immintrin.h>
#endif

size_t *mine_location(size_t n, const int *field)
{
    size_t *loc = calloc(2, sizeof(size_t));
    size_t n2 = n * n;
    size_t i = 0;
#ifdef __AVX2__
    size_t vi;
    if (vi = n2 >> 3 << 3) {
        __m256i b = _mm256_set1_epi32(1);
        int msk;
        do {
            if (msk = _mm256_movemask_ps((__m256)_mm256_cmpeq_epi32(_mm256_loadu_si256((__m256i const *)(field+i)), b))) {
                i += __builtin_ffs(msk) - 1, n2 = 0;
                break;
            }
        } while ((i += 8) < vi);
    }
#endif
    for ( ; i < n2; ++i)
        if (field[i])
            break;
    __asm__ __volatile__("mov %2, %%rax\n\t"
                        "xor %%edx, %%edx\n\t"
                        "div %3\n\t"
                        "mov %%rax, %0\n\t"
                        "mov %%rdx, %1\n\t"
                        : "=m"(loc[0]), "=m"(loc[1])
                        : "r"(i), "r"(n)
                        : "rax", "rdx"
    );
    return loc;
}

/////////////////////////
