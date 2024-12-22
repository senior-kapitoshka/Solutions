#include <algorithm>
int countLettersAndDigits(std::string in)
{
    int ans=0;
  for_each(in.begin(),in.end(),[&ans](auto& i){if(isdigit(i)||isalpha(i)) ++ans;});
  return ans;
}
//////////////////////////////////
int countLettersAndDigits(std::string input)
{
    return count_if( input.begin(), input.end(), isalnum );
}
//////////////////////////////
