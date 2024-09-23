#include <printf.h>
#include <stdlib.h>
#include <regex.h>
#include <stdio.h>


/* Return 1 is addr is a valid IP address, return 0 otherwise */
int is_valid_ip(const char * addr) {
    char * regex_src =
            "^(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\."
            "(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\."
            "(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\."
            "(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$";
    regex_t regex;
    int reti;
    char msgbuf[100];
    int result;

    reti = regcomp(&regex, regex_src, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    reti = regexec(&regex, addr, 0, NULL, 0);
    if (!reti) result = 1;
    else if (reti == REG_NOMATCH) result = 0;
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    regfree(&regex);

    return result;
};



///////////////////////
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>


int is_valid_ip(const char * addr) {

    regex_t regex;
    
    if(regcomp(&regex, "^(25[0-5]|2[0-4][0-9]|[0-1][0-9]{2}|[0-9]{2}|[0-9])(\\.(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[0-9]{2}|[0-9])){3}$", REG_EXTENDED | REG_ICASE ) != 0)
    {
    printf("Compilation error!");
    exit(EXIT_FAILURE);
    }
   // else printf("Successful!");
    
    int result = regexec(&regex, addr, 0, NULL, 0);
    if(result == 0) return 1;
    return 0;
    

};

//////////////////////////////
#include <arpa/inet.h>

/* Return 1 is addr is a valid IP address, return 0 otherwise */
int is_valid_ip(const char *addr) {
  struct sockaddr_in sockaddr;
  return inet_pton(AF_INET, addr, &(sockaddr.sin_addr)) ? 1 : 0;
}

/////////////////////////////
#include <stdio.h>

int is_valid_ip(const char *addr)
{
 unsigned n[4], i, nc;
 
 // Must be 4 integers separated by dots:
 if( sscanf(addr, "%d.%d.%d.%d%n", &n[0], &n[1], &n[2], &n[3], &nc) != 4 )
   return 0;
   
 // Leftover characters at the end are not allowed:
 if( nc != strlen(addr) )
   return 0;
   
 // Leading zeros and space characters are not allowed:
 if( addr[0] == '0' || strstr(addr, ".0") || strchr(addr, ' ') )
   return 0;
 
 // Values > 255 are not allowed:
 for(i=0; i<4; i++)
   if( n[i] > 255 )
     return 0;
  
 return 1;
};

////////////////////
/* Return 1 is addr is a valid IP address, return 0 otherwise */
#include <string.h>
#include <stdio.h>

int is_valid_ip(const char * addr) {
  unsigned char a,b,c,d;
  char test[30];
  sscanf(addr, "%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
  snprintf(test, 30, "%hhu.%hhu.%hhu.%hhu", a, b, c, d);
  return strcmp(addr, test)==0;
};

/////////////////////
#include <arpa/inet.h>
int is_valid_ip(const char * addr) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, addr, &(sa.sin_addr));
    return (result != 0)? 1 : 0;
};