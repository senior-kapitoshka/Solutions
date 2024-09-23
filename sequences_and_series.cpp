int getScore(int n) {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
   res += 50*i;
  }
  return res;
}

/////////////////////
int getScore(int n) {
  return 50*n*(n+1)/2;
}

////////////
int getScore(int n) {
  return 25 * n * (n + 1);
}

//////////////