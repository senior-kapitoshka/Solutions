char *ones_complement (const char *bs, char *res)
{
  char* p=res;
  for(;*bs;++bs){
    *p++=*bs=='1'?'0':'1';
  }
	*p = '\0'; // write to complement
	return res; // return it
}

/////////////////////
char *ones_complement (const char *bitstring, char *complement)
{
    char *p = complement;
    while (*bitstring)
        *p++ = *bitstring++ ^ 1;
    *p = '\0';
    return complement;
}
/////////////////
char *ones_complement(const char *bitstring, char *complement)
{
    char* p = complement;

    while (*bitstring)
    {
        *p++ = "10"[*bitstring++ - '0'];
    }

    return *p = 0, complement;
}