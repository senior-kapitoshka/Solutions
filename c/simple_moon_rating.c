char *moon_rating (char moons[5 + 1], double rating)
{
  char *p=moons;
    for(int i=0;i<5;++i){
      if(rating>=1.5) *p++='o';
      else if(rating<2.0 && rating>=0.5)  *p++='c';
      else  *p++='x';
      rating-=2.0;
    }
    *p = '\0';
    return moons;
}
/////////////
#include <string.h>
#include <math.h>

static char* M[] = {
  "xxxxx","cxxxx","oxxxx","ocxxx","ooxxx",
  "oocxx","oooxx","ooocx","oooox","ooooc","ooooo"
};

char *moon_rating(char moons[5 + 1], double rating)
{
  return strcpy(moons, M[(int)(round(rating))]);
}
///////////
char *moon_rating (char moons[5 + 1], double rating)
{
  int r = round(rating);
  sprintf(moons, "%.*s%.*s%.*s", r / 2, "ooooo", r % 2, "ccccc", 5 - r / 2 - r % 2, "xxxxx");
	return moons;
}