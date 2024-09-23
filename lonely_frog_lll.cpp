unsigned jumpTo(unsigned x, unsigned y) {
  int cnt=0;
  while(y>x){
    if(y%2==0 && y/2>=x){
      y/=2;
    }else{
      y-=1;
    }
    ++cnt;
  }
  return cnt;
}

//////////////////
unsigned jumpTo(unsigned x, unsigned y)
{
	unsigned temp = y;

	int count = 0;

	while(temp != x)
	{
		temp = temp % 2 == 1 ? temp - 1 : (temp / 2) >= x ? temp / 2 : temp - 1;
		count++;
	}

	return count;
}

////////////////
unsigned jumpTo(unsigned x, unsigned y) {
  int moves = 0;
  while(y ^ x){
    ++moves;
    if(y & 1)
      --y;
    else if((y>>1) >= x)
      y >>= 1;
    else
      --y;
  }
  return moves;
}


/////////////////////
unsigned jumpTo(unsigned x, unsigned y) {
  return y < 2*x ? y-x : 1 + y%2 + jumpTo(x, y/2);
}

///////////////
