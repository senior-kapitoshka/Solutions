char *move_marks (const char *in, char *out)
{
	char* p=out;
  int cnt=0;
  for(;*in;++in){
    if(*in=='!'){
      ++cnt;
    }else{
      *p++=*in;
    }
  }
  while(cnt--){
    *p++='!';
  }
  *p='\0';
	return out; 
}

////////////////
