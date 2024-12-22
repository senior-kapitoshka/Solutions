#include <numeric>

int fish(std::string s) {
  if(s.empty()) return 1;
  int size=1;
  std::sort(s.begin(),s.end());
  int sum=std::accumulate(s.begin(),s.end(),0,
                         [&size](int& sum,auto& curr)
                         {

                           if (sum >= size * 4) {
                             ++size;
                             sum = 0;
                           }
                           return sum+=(size >=(curr-'0'))?(curr-'0'):0;
                           
                         }); 
  if (sum >= size * 4) {
   ++size;
 }
  return size;
}

////////////////////
int fish(std::string shoal)
{
   int size = 1;
   int eaten = 0;
   int nextSize = size * 4;
   std::sort(shoal.begin(), shoal.end());
   for (auto c : shoal)
   {
     int fishSize = c - '0';
     if (size >= fishSize)
       eaten += fishSize;
    
    
     if (eaten >= nextSize)
     {
       size++;
       nextSize += size * 4;
     }
    }
    return size;
}

//////////////////
#include <map> 
#include <string>
#include <vector>

int fish(std::string shoal) {
	// do your thing :)

	std::map<char, int> table;
	for (auto x : shoal) table[x-'0']++;

	int total = 0;
	int r = 0, sum = 0;
	while (sum >= total) {
		r++;
		total += 4 * r;
		sum += r * table[r];
	}
	return r;
}

/////////////

