#include <stdbool.h>
#include <string.h>

bool validate_username (const char *un){
  if(strlen(un)<4 || strlen(un)>16) return false;
  for(;*un;++un){
    if((isalpha(*un) && islower(*un)) || isdigit(*un) || *un=='_' ) continue;
    else return false;
  }
	return true;
}

/////////////////
#include <stdbool.h>
#include <stdlib.h>
#include <regex.h>

bool validate_username (const char *username) {
  regex_t rx;
  int rsp;
  
  if(regcomp(&rx, "^[a-z0-9_]\\{4,16\\}$", 0)) return false;
  
  rsp = regexec(&rx, username, 0, NULL, 0);

	return !rsp;
}

///////////////
