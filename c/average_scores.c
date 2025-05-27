#include <stddef.h>
#include <math.h>

void sum(const int vs[/* count */], size_t cnt, int* res){
  if(cnt==-1) return;
  *res+=vs[cnt];
  return sum(vs,cnt-1,res);
}
int average(const int vs[/* count */], size_t cnt)
{
  int res=0;
  sum(vs,cnt-1,&res);
  return round(res/(cnt*1.0));
}


//////////////////
int sum(const int *values, unsigned int count)
{
  if(count == 0) return 0;
  else return values[0] + sum(values+1, count-1);
}

int average(const int *values, unsigned int count){
  double avg = sum(values, count) / (double) count;
  return avg + 0.5;
}
//////////
#include <stdio.h>
#include <math.h>

int g_count = 0;
int average(const int *values, size_t count) {
  float avg = values[count-1];

  if (!g_count)
    g_count = count;
  if (count > 1)
    avg += average(values, count-1);
  if (g_count == count) {
    avg = round(avg / g_count);
    g_count = 0;
  }
  return avg;
}
///////////
#include <stddef.h>
#include <math.h>

int average(const int values[/* count */], size_t count)
{
    unsigned int i = 0;
    float sum = 0;
start:    
    if(i == count)
        goto end;
    sum += values[i];
    i++;
    goto start;
end:    
    return round(sum / count);
}
/////////////
int average(const int *values, int count)
{
	double average=0;
	int i=0;
	jump:
		{
			if(i==count) return ((average/count)-(int)(average/count))>=0.5? (int)(average/count)+1 : (int)(average/count);
			average+=values[i];
			i++;
			goto jump;
		}
}
/////////
#include <stdlib.h>

f(*a, n) { return n ? *a + f(a + 1, --n) : 0; }

average(*a, n) { return .5 + 1. * f(a, n) / n; }