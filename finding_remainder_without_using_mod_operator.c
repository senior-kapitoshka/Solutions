unsigned modlulo(unsigned dd, unsigned dr) {
  while(dd>=dr){dd-=dr;}
    return dd;
}
/////////
unsigned modlulo(unsigned dividend, unsigned divisor) {
    return dividend - (dividend / divisor) * divisor;
}