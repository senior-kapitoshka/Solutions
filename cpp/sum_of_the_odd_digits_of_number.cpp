int sum_odd_digits(int n)
{
  if(n==0 || n==1)return n;
 return (n%10)%2!=0?(n%10)+sum_odd_digits(n/10):sum_odd_digits(n/10);
}

/////////////////////////
int sum_odd_digits(int n, int res = 0) {
    return n > 0 ? sum_odd_digits(n / 10, res + (n % 2 ? n % 10 : 0)) : res;
}
//////////////////
int sum_odd_digits(int n)
{
    return !n ? 0 : (n & 1 ? n % 10 : 0) + sum_odd_digits(n / 10);
}
///////////////////
int sum_odd_digits(int n)
{
  if(n==0) return 0;
  return ( (n%10 &1) ? (n%10 + sum_odd_digits(n/10)) : sum_odd_digits(n/10)); 
}
//////////////
