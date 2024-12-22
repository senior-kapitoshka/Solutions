int byte_to_set (unsigned char b, int set[8])
{
// fill set[], return the set size
// the order of set elements does not matter
  short cnt=7;
  short i=0;
	while(b>1){
    if(b%2==1){
      set[i++]=cnt;
    }
    --cnt;
    b/=2;
  }
  if(b%2==1){
      set[i++]=cnt;
  }
  return i;
}

///////////////////////////////
int byte_to_set (unsigned char byte, int set[8])
{
    int i, cnt, shf = 8;
  
    if (!byte) 
        return 0;
    for (i = cnt = 0; shf--; ++i)
        if (byte >> shf & 1)
          set[cnt++] = i;
    return cnt;
}

//////////////////
enum { N = 8 };

int byte_to_set (unsigned char byte, int set[N])
{
	int len = 0;
	for (int i = N - 1; i >= 0; i--, byte >>= 1)
		if (byte & 1)
			set[len++] = i;
	return len;
}

///////////////////
int byte_to_set (unsigned char byte, int set[8])
{
// fill set[], return the set size
// the order of set elements does not matter
	//set[0] = 3;
  unsigned char mask=2*2*2*2*2*2*2;
  int j=0;
  for(int i=0;i<8;i++)
    {
    if(mask&byte)
      set[j++]=i;
    mask/=2;
  }
	return j;
}