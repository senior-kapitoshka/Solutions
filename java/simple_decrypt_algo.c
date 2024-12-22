void decrypt(const char *e, char *k) {
  int arr[26]={0};
  for(;*e;++e) if(isalpha(*e) && islower(*e)) ++arr[*e-97];
  char*p=k;
  for(int i=0;i<26;++i){
    *p++=arr[i]+'0';
  }
  *p='\0';
}

/////////////////
void decrypt(const char *encryption, char *key) {
    char c;
    for (int i = 0; i <= 26; i++) key[i] = i == 26 ? '\0' : '0';
    while (c = *encryption++) key[c - 'a'] += c >= 'a' && c <= 'z';
}
//////////////////
#include <string.h>

void decrypt(const char *encryption, char *key)
{
  memset(key, '0', 26), key[26] = '\0';
  for (char *p = (char *)encryption; *p; p++)
    if (*p >= 'a' && *p <= 'z')
      key[*p - 'a'] = ++key[*p - 'a'];
}
//////////////
void decrypt(const char *encryption, char *key) {
  key[26] = 0;
  memset(key, '0', 26);
  while (*encryption) {
    if (*encryption >= 'a' && *encryption <= 'z')
      ++key[*encryption - 'a'];
    ++encryption;
  }
}

/////////////////