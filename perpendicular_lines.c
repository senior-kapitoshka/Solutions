unsigned max_bisectors(unsigned n) {
    return n%2==0?((n/2)*(n/2)):((n/2)*(n/2)+n/2);
}

//////////////////////////
unsigned max_bisectors(unsigned n) {
  return n * n / 4;
}

///////////////////
unsigned max_bisectors(unsigned n) {

    return (n*n) >> 2;

}