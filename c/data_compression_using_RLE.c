#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
struct Node{
  char v;
  unsigned cnt;
};

char *encode (char *ed, const char *s)
{
  if(*s=='\0') {
    *ed='\0';
    return ed;
  }
  struct Node n={*s,1};
  ++s;
  char* p=ed;
  for(;*s;++s){
    if(*s==n.v){
      ++n.cnt;
    }else{
      p+=sprintf(p,"%d%c",n.cnt,n.v);
      n.v=*s;
      n.cnt=1;
    }
  }
  p+=sprintf(p,"%d%c",n.cnt,n.v);
	*p = '\0'; // write to encoded
	return ed; // return it
}

char* to_string(char d[10], char a){
  unsigned n=atoi(d);
  char* t=calloc(n+1,1);
  char*p=t;
  while(n--){
    *p++=a;
  }
  *p='\0';
  return t;
}

char *decode (char *s, const char *ed)
{
  if(*ed=='\0') {
    *s='\0';
    return s;
  }
  char* p=s;
  short flag=0;
  char buf[10];
 for(int i=0;*ed;++ed){
   if(isdigit(*ed) && !flag){
     flag=1;
     i=0;
     buf[i++]=*ed;
   }else if(isdigit(*ed) && flag){
     buf[i++]=*ed;
   }else if(isalpha(*ed) && flag){
     buf[i++]='\0';
     flag=0;
     char* t=to_string(buf,*ed);
     p+=sprintf(p,"%s",t);
     free(t);
   }
 } 
	*p = '\0'; // write to string
	return s; // return it
}

/////////////////////////
#include <stdio.h>

char *encode (char *encoded, const char *string)
{
	*encoded = '\0';
	char *retval = encoded;
	unsigned count = 1;

	for (; *string; string++) {
		if (string[0] == string[1]) {
			count++;
		} else {
			encoded += sprintf(encoded, "%u%c", count, *string);
			count = 1;
		}
	}
	return retval;
}

char *decode (char *string, const char *encoded)
{
	char *retval = string;
	int nb_scanned;
	unsigned count;
	char value;

	for (; sscanf(encoded, "%u%c%n", &count, &value, &nb_scanned) == 2; encoded += nb_scanned)
		for (unsigned i = 0; i < count; i++)
			*(string++) = value;

	*string = '\0';
	return retval;
}

///////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode a string using a simple run-length encoding scheme
// Returns a pointer to the encoded string

char *encode(char *encoded, const char *string) {

  *encoded = '\0'; // Initialize the encoded string
  
  char *retval = encoded; // Save the starting position of the encoded string
  
  unsigned count = 1; // Initialize count for consecutive characters

    // Loop through the input string
    for (; *string; string++) {
        if (string[0] == string[1]) {
            // If the current character is the same as the next one, increase the count
            count++;
        } else {
            // If the current character is different from the next one, append count and character to the encoded string
            encoded += sprintf(encoded, "%u%c", count, *string);
            count = 1; // Reset count for the new character
        }
    }
    return retval; // Return the pointer to the encoded string
}

// Function to decode a string encoded using the run-length encoding scheme

// Returns a pointer to the decoded string

char *decode(char *string, const char *encoded) {

  char *retval = string; // Save the starting position of the decoded string
  
  int nb_scanned; 
  
  unsigned count; // Variable to store the count of consecutive characters
  
  char value; 
  
  
  
  
  
  // Loop through the encoded string
  
  for (; sscanf(encoded, "%u%c%n", &count, &value, &nb_scanned) == 2; encoded += nb_scanned) {
  
    // Repeat the character according to the count
    
    
    
    for (unsigned i = 0; i < count; i++) {
    
      *(string++) = value;
      
    }
    
  }

  
  
  *string = '\0'; // Add null terminator at the end of the decoded string
  
  return retval; // Return the pointer to the decoded string
}
