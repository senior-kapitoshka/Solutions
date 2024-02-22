int64_t fact(int n){
  if(n==0) return 1;
  return n*fact(n-1);
}

/*int projectPartners(int n){
  if(n==0||n==1) return 0;
  if(n==2) return 1;
  return  (fact(n)/(2*fact(n-2)));
}*/
int projectPartners(int n){
  if(n==0||n==1) return 0;
  if(n==2) return 1;
  return n * (n-1) / 2;
  }
  //////////////////////////////////
  int projectPartners(int n)
{
    int count = 0;
    for (int i=1; i<n; ++i) { count += i; }
    return count;
}
/////////////////////////////
int projectPartners(int n){
  int wynik=0;
  for (int i=1; i<n+1; i++){
    wynik+=(i-1);
  }
  return wynik;
}
//////////////////////////
int projectPartners(int n){
  return  n < 2 ? 0 : n-1 + projectPartners( n-1 ) ;
}
//////////////////////
#include <cmath>
int projectPartners(int n) {
    return round(tgamma(n + 1) / (2 * tgamma(n - 1)));
}