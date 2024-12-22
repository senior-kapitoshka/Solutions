typedef struct Node{
  int val;
  unsigned n;
}Node;

unsigned calc_bits(int x){
  unsigned cnt=0;
  while(x!=1){
    if(x%2==1)++cnt;
    x/=2;
  }
  return cnt;
}

int compar(const void *s1, const void *s2)
{
  struct Node *n1 = (struct Node *)s1;
  struct Node *n2 = (struct Node *)s2;
  int cmp = n1->n-n2->n;
 return cmp==0?n1->val-n2->val:cmp;
}

void sort_by_bit(int * arr, int l){
  struct Node a[l];
    for(int i=0;i<l;++i){
      Node n={arr[i],calc_bits(arr[i])};
      a[i]=n;
    }
  qsort(a,l,sizeof(Node),compar);
  for(int i=0;i<l;++i){
    arr[i]=a[i].val;
  }
}

/////////////////
static int bits(int x) {
  int n = 0;
  do { n += x & 1; } while (x >>= 1 > 0);
  return n;
}

static int cmpfunc (const void * pa, const void * pb) {
  int a = *(int *)pa, b = *(int *)pb, bit_diff;
  return (bit_diff = bits(a) - bits(b)) == 0 ? a - b : bit_diff;  
}

void sort_by_bit(int * arr, int arrLength) {
   qsort(arr, arrLength, sizeof(int), cmpfunc);
}

//////////////////////
int comp(const void * a, const void * b){
    int oba = __builtin_popcount(*(int *) a),
        obb = __builtin_popcount(*(int *) b);
    return oba == obb ? (*(int *) a - *(int *) b) : (oba - obb);
}

void sort_by_bit(int * arr, int n){
    qsort(arr, n, sizeof(*arr), comp);
}
//////////////////
int bits(int n) {
  int r = 0;
  while (n) {
    r++;
    n &= n - 1;
  }
  return r;
}

int cmp(const void *a_ptr, const void *b_ptr) {
  int a = *(int *)a_ptr;
  int b = *(int *)b_ptr;
  int d = bits(a) - bits(b);
  return d != 0 ? d : (a < b ? -1 : a == b ? 0 : 1);
}

void sort_by_bit(int *arr, int arrLength) {
  qsort(arr, arrLength, sizeof(int), cmp);
}