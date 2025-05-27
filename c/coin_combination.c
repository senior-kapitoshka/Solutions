void coin_combo (unsigned c, unsigned cns[4])
{
  for(int i=0;i<4;++i)cns[i]=0;
	while(c>0){
    if(c>=25){
      c-=25;
      ++cns[3];
    }else if(c>=10){
      c-=10;
      ++cns[2];
    }else if(c>=5){
      c-=5;
      ++cns[1];
    }else if(c>=1){
      c-=1;
      ++cns[0];
    }
  }
}

///////////////
void coin_combo(unsigned cents, unsigned coins[4]) {
    coins[3] = cents / 25;
    coins[2] = (cents %= 25) / 10;
    coins[1] = (cents %= 10) / 5;
    coins[0] = (cents %= 5);
}
////////////
void coin_combo (unsigned cents, unsigned coins[4])
{
  unsigned cent=cents,cen=cents,ce=cents,c=cents;
	coins[3]=cent/25;
  coins[2]=cen%25/10;
  coins[1]=ce%25%10/5;
  coins[0]=c%25%10%5;
  
}
/////////////
void coin_combo (unsigned c, unsigned coins[4])
{
  static unsigned vals[] = {25, 10, 5, 1, 0};
  
  for (unsigned *p = &coins[3], *v = vals; *v;)
    *p = c / *v, c -= *p-- * *v++;
}